/*
make a music player using circular queue which can perform actions like undo, add songs, repeat last song including counting down
the time remaining for song to finish
*/

#include <stdio.h>
#include <stdlib.h>

#define size 50

typedef struct song
{
    char song_name;
    int time;
} song;

song *stack[size];
song *queue[size];
int top = -1;
int rear = 0;
int front = 0;

void AddSong(song *s)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue is Full");
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = s;
    }
}

void PlaySong()
{
    front = (front + 1) % size;
    song *s = queue[front];
    printf("Song: %s\n", &s->song_name);
    for (int i = s->time; i >= 0; i--)
    {
        printf("Remaining time: %d\n", i);
    }
    stack[++top] = s;
}

void undo()
{
    if (top > -1)
    {
        song *s = stack[top--];
        AddSong(s);
    }
    else
    {
        printf("No song to undo!!");
    }
}

int main()
{
    int ch;
    printf("Welcome to Spotify\n");
    while (1)
    {
        printf("Choose\n1.Play song\n2.Add song\n3.Undo\n4.Exit\n");
        printf("Enter: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Playing Song:\n");
            PlaySong();
            break;
        case 2:
            printf("Add Song: ");
            song *s = (song *)malloc(sizeof(song));
            printf("Enter name of song: ");
            printf("\n");
            scanf("%s", &(s->song_name));
            printf("Enter duration: ");
            scanf("%d", &s->time);
            AddSong(s);
            break;
        case 3:
            undo();
            break;
        case 4:
            printf("Exitiing Spotify....");
            return 0;
        }
    }
}

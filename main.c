#include "queue.h"

Pos goal;
Pos *first;
Queue *queue;
void init();
int check_success(Pos *pos);
Pos *run();
Pos *addPos(int x, int y, int nr_moves);
int nr_moves_changed;

int main()
{
    nr_moves_changed = 0;
    init();
    if(check_success(queue->front->pos) == 0) {
        Pos *pos = run();
        printf("Det kravs minst %d promenader\n", pos->nr_moves);
    } else {
        printf("Du var ju redan framme...");
    }
    return 0;
}

Pos *run() {
    int done_flag = 0;
    Pos *current_pos;
    while(done_flag == 0) {
        if(isEmpty(queue) == 0) {
            free(current_pos);
            current_pos = dequeue(queue);
            if(check_success(current_pos) == 0) {
                enqueue(queue, addPos(current_pos->x, current_pos->y + 8, current_pos->nr_moves + 1));  //North
                enqueue(queue, addPos(current_pos->x, current_pos->y - 3, current_pos->nr_moves + 1));  //South
                enqueue(queue, addPos(current_pos->x - 6, current_pos->y, current_pos->nr_moves + 1));  //West
                enqueue(queue, addPos(current_pos->x + 5, current_pos->y, current_pos->nr_moves + 1));  //East
            } else {
                done_flag = 1;
            }
        }else {
            done_flag = 1;
        }
        //Prints when the search traverses into the next level of the tree
        if(nr_moves_changed != current_pos->nr_moves) {
            printf("nr_moves: %d\n", current_pos->nr_moves);
            nr_moves_changed = current_pos->nr_moves;
        }
        //No solution found, break.
        if(current_pos->nr_moves > 30) return current_pos;
    }
    return current_pos;
}

Pos *addPos(int x, int y, int nr_moves) {
    Pos *pos = (Pos*)malloc(sizeof(Pos));
    pos->x = x;
    pos->y = y;
    pos->nr_moves = nr_moves;
    return pos;
}

void init() {
    queue = initQueue();
    int start_x;
    int start_y;
    printf("Start x: ");
    scanf("%d", &start_x);
    printf("Start y: ");
    scanf("%d", &start_y);

    goal.x = 0;
    goal.y = 0;
    first = (Pos*)malloc(sizeof(Pos));
    first->x = start_x;
    first->y = start_y;
    first->nr_moves = 0;
    enqueue(queue,first);
}

int check_success(Pos *pos) {
    if(pos->x == goal.x && pos->y == goal.y) {
        printf("Victory! Goal has been found!\n\n");
        return 1;
    }
    return 0;
}

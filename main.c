#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_NAME_LEN 20
#define MAX_EMAIL_LEN 20

typedef struct Node {
    int id;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int next_id;
    int next_name; 
    int next_email; 
} Node;

typedef struct List {
    Node* buffer;
    unsigned int length;
    unsigned int capacity;
    // Invalid value is -1
    int head_id;
    int head_name;
    int head_email;
} List;

int init_list(List* list);
int push_node(List* list, Node n);
void init_node(Node* n);
void print_list_id(List* list);
void print_list_name(List* list);
void print_list_email(List* list);
void print_node(Node* n);

int main() {
    List list;
    init_list(&list);
    Node n1, n2, n3, n4, n5, n6;
    Node n7, n8, n9, n10, n11, n12, n13;
    init_node(&n1);
    init_node(&n2);
    init_node(&n3);
    init_node(&n4);
    init_node(&n5);
    init_node(&n6);
    init_node(&n7);
    init_node(&n8);
    init_node(&n9);
    init_node(&n10);
    init_node(&n11);
    init_node(&n12);
    init_node(&n13);
    n1.id = 5;
    n2.id = 4;
    n3.id = 10;
    n4.id = 2;
    n5.id = 7;
    n6.id = 11;
    n7.id = 0;
    n8.id = 1;
    n9.id = 34;
    n10.id = 18;
    n11.id = 11;
    n12.id = 17;
    n13.id = 4;

    strncpy(n1.name, "Dusan", MAX_NAME_LEN);
    strncpy(n2.name, "Nemanja", MAX_NAME_LEN);
    strncpy(n3.name, "Jovana", MAX_NAME_LEN);
    strncpy(n4.name, "Ana", MAX_NAME_LEN);
    strncpy(n5.name, "Maja", MAX_NAME_LEN);
    strncpy(n6.name, "Aleksa", MAX_NAME_LEN);
    strncpy(n7.name, "a", MAX_NAME_LEN);
    strncpy(n8.name, "aa", MAX_NAME_LEN);
    strncpy(n9.name, "aaa", MAX_NAME_LEN);
    strncpy(n10.name, "aaaa", MAX_NAME_LEN);
    strncpy(n11.name, "aaaaaa", MAX_NAME_LEN);
    strncpy(n12.name, "aaaaaaaaa", MAX_NAME_LEN);
    strncpy(n13.name, "aaaaaaaaaaaaa", MAX_NAME_LEN);
    strncpy(n1.email, "dusan@dusan.com", MAX_EMAIL_LEN);
    strncpy(n2.email, "cone@cone.com", MAX_EMAIL_LEN);
    strncpy(n3.email, "jvn@jvn.com", MAX_EMAIL_LEN);
    strncpy(n4.email, "ana@ana.com", MAX_EMAIL_LEN);
    strncpy(n5.email, "maja@maja.com", MAX_EMAIL_LEN);
    strncpy(n6.email, "aleksa@aleksa.com", MAX_EMAIL_LEN);
    strncpy(n7.email, "llllllllllll", MAX_EMAIL_LEN);
    strncpy(n8.email, "ll", MAX_EMAIL_LEN);
    strncpy(n9.email, "l", MAX_EMAIL_LEN);
    strncpy(n10.email, "lllllllllllllllllll", MAX_EMAIL_LEN);
    strncpy(n11.email, "lllllllllll", MAX_EMAIL_LEN);
    strncpy(n12.email, "lllll", MAX_EMAIL_LEN);
    strncpy(n13.email, "lllllll", MAX_EMAIL_LEN);

    push_node(&list, n1);
    push_node(&list, n2);
    push_node(&list, n3);
    push_node(&list, n4);
    push_node(&list, n5);
    push_node(&list, n6);
    push_node(&list, n7);
    push_node(&list, n8);
    push_node(&list, n9);
    push_node(&list, n10);
    push_node(&list, n11);
    push_node(&list, n12);
    push_node(&list, n13);

    printf("\nList sorted by id:\n");
    print_list_id(&list);
    printf("\nList sorted by name length:\n");
    print_list_name(&list);
    printf("\nList sorted by email length:\n");
    print_list_email(&list);
    

    return 0;

}

void print_node(Node* n) {
    printf("ID: %3d NAME: %20s EMAIL: %20s NEXT_ID: %3d NEXT_NAME: %3d NEXT_EMAIL %3d\n", n->id, n->name, n->email, n->next_id, n->next_name, n->next_email);
}

void init_node(Node* n) {
    n->next_id = -1;
    n->next_name = -1;
    n->next_email = -1;
}

void print_list_email(List* list) {
    if (list == NULL || list->head_email== -1) {
        printf("List is empty\n");
        return;
    }
    
    int tmp_index = list->head_email;
    while(tmp_index != -1) {
        print_node(list->buffer + tmp_index);
        tmp_index = list->buffer[tmp_index].next_email;
    }
}

void print_list_name(List* list) {
    if (list == NULL || list->head_name == -1) {
        printf("List is empty\n");
        return;
    }
    
    int tmp_index = list->head_name;
    while(tmp_index != -1) {
        print_node(list->buffer + tmp_index);
        tmp_index = list->buffer[tmp_index].next_name;
    }
}
void print_list_id(List* list) {
    if (list == NULL || list->head_id == -1) {
        printf("List is empty\n");
        return;
    }
    
    int tmp_index = list->head_id;
    while(tmp_index != -1) {
        print_node(list->buffer + tmp_index);
        tmp_index = list->buffer[tmp_index].next_id;
    }
}
void print_list(List* list) {
    if (list == NULL || list->head_id == -1) {
        printf("List is empty\n");
        return;
    }
    
    int tmp_index = list->head_id;
    while(tmp_index != -1) {
        print_node(list->buffer + tmp_index);
        tmp_index = list->buffer[tmp_index].next_id;
    }
}

int init_list(List* list) {
    if (list == NULL) {
        return 1;
    } 

    list->length = 0;
    list->capacity = 16;
    list->head_id = -1;
    list->head_name = -1;
    list->head_email = -1;

    list->buffer = (Node*)malloc(sizeof(Node) * list->capacity);
    
    if (list->buffer == NULL) {
        return 1;
    }

    return 0;
}

int push_node(List* list, Node n) { 
    if (list->length == list->capacity) {
        list->capacity *= 2;
        Node* new_buffer = realloc(list->buffer, sizeof(Node) * list->capacity);

        if (new_buffer == NULL) {
            return 1;
        }

        list->buffer = new_buffer;
    }


    if (list->head_id == -1) {
        list->head_id = 0;
        list->head_name = 0;
        list->head_email = 0;
        n.next_id = -1;
        list->buffer[list->head_id] = n;
        list->length += 1;
        return 0;
    }
    
    // If new node should go at the start
    if (n.id >list->buffer[list->head_id].id) {
        n.next_id = list->head_id;
        list->head_id = list->length;
    }

    if (strlen(n.name) > strlen(list->buffer[list->head_name].name)) {
        n.next_name = list->head_name;
        list->head_name = list->length;
    }
    
    if (strlen(n.email) >strlen( list->buffer[list->head_email].email)) {
        n.next_email = list->head_email;
        list->head_email = list->length;
    }

    
    // Find where node should be placed based on id
    if (n.next_id == -1) {
        int last_index = list->head_id;
        Node tmp = list->buffer[last_index];

        while(tmp.next_id != -1 && list->buffer[tmp.next_id].id > n.id) {
            last_index = tmp.next_id;
            tmp = list->buffer[tmp.next_id];
        }

        n.next_id = tmp.next_id;
        tmp.next_id = list->length;
        list->buffer[last_index] = tmp;

    }

    // Find where node should be placed based on name
     if (n.next_name == -1) {
         int last_index = list->head_name;
         Node tmp = list->buffer[last_index];

         while(tmp.next_name != -1 && strlen(list->buffer[tmp.next_name].name) > strlen(n.name)) {
             last_index = tmp.next_name;
             tmp = list->buffer[tmp.next_name];
         }

         n.next_name = tmp.next_name;
         tmp.next_name = list->length;
         list->buffer[last_index] = tmp;
     }
    

    // Find where node should be placed based on email 
    if (n.next_email == -1) {
        int last_index = list->head_email;
        Node tmp = list->buffer[last_index];

        while(tmp.next_email != -1 && strlen(list->buffer[tmp.next_email].email) > strlen(n.email)) {
            last_index = tmp.next_email;
            tmp = list->buffer[tmp.next_email];
        }

        n.next_email = tmp.next_email;
        tmp.next_email = list->length;
        list->buffer[last_index] = tmp;
    }

    // Finally save node to the buffer
    list->buffer[list->length] = n;
    list->length += 1;

    return 0; 
}

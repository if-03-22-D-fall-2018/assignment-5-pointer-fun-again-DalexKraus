#include <stdio.h>
#include <string.h>

struct PlayStruct
{
    int int_value;
    double double_value;
    char a_string[64];
};

void print_struct(struct PlayStruct ps, struct PlayStruct* pps);
void change_struct(struct PlayStruct ps, struct PlayStruct* pps);
void print_string(char string_to_print[]);
void change_string(char string1[], char* p_string);

int main(int argc, char const *argv[])
{
    struct PlayStruct play_struct;
    play_struct.int_value = 16;
    play_struct.double_value = 20.18;
    strcpy(play_struct.a_string, "David Kraus");

    struct PlayStruct* play_struct_pointer;
    play_struct_pointer = &play_struct;
    /*
        It is useful to assign the address of the declared struct play_struct
        to the pointer play_struct_pointer.
        Using the pointer, we can access the variables of the struct later on.
    */

    print_struct(play_struct, play_struct_pointer);

    change_struct(play_struct, play_struct_pointer);
    print_struct(play_struct, play_struct_pointer);
    /*
        Only the struct to which the pointer was pointing changed,
        because the first struct is passed by value, which is
        deleted the moment after the change_struct function terminates.
    */

    print_string(play_struct.a_string);
    char name[16] = "Lilli";
    change_string(play_struct.a_string, &name);
    print_string(play_struct.a_string);
    print_string(&name);
    /*
        The value of the struct is not changed because the content of the
        struct is only copied at function call.
        But because the pointer points to a variable on the stack,
        it can be modified even if it's not in the same function.
        This is possible because the content of that address (towards the
        pointer is pointing) is changed.
    */

    return 0;
}

void print_struct(struct PlayStruct ps, struct PlayStruct* pps)
{
    printf("Values of struct ps: %d, %lf, %s\n", ps.int_value, ps.double_value, ps.a_string);
    printf("Values of struct pps: %d, %lf, %s\n", pps->int_value, pps->double_value, pps->a_string);
}

void change_struct(struct PlayStruct ps, struct PlayStruct* pps)
{
    ps.int_value = 5;
    ps.double_value = 203.93;
    strcpy(ps.a_string, "Schnitzel");

    pps->int_value = 39;
    pps->double_value = 3.14159265359;
    strcpy(pps->a_string, "Pizza");
}

void print_string(char string_to_print[])
{
    printf("%s\n", string_to_print);
}

void change_string(char string1[], char* p_string)
{
    string1[2]  = '\0';
    //p_string[1] = '\0';
}

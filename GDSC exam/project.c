#include "project.h"
static char arr[5]={0};
static inline void show_exam(quistion_t exam_arr[5]){

    for(int i=0 ; i<5 ; i++){
        printf("%s\n",exam_arr[i].text);
        printf("-------------\n");
    }

}
void c_exam(void){
    quistion_t exame_ques[5]={0};
    strcpy(exame_ques[0].text , "What is the output of the following C code?*\n #include <stdio.h> \n int main() {\n int x = 5;\n printf('%d', x++);\n return 0;}\n [a] 5 [b] 6 [c] 4 [d] 7");
    exame_ques[0].correct_ans = 'b';
    exame_ques[0].degree=5;
    arr[0]= exame_ques[0].correct_ans;
    strcpy(exame_ques[1].text , "Which of the following is not a valid data type in C?\n a-  float [b]  char* [c] long double [d] boolean");
    exame_ques[1].correct_ans = 'd';
    exame_ques[1].degree=5;
    arr[1]= exame_ques[1].correct_ans;
    strcpy(exame_ques[2].text , " What will be the value of 'result' after the following C code is executed?*\n #include <stdio.h> \n int main() {\n nt a = 10, b = 3;\n float result = (float)a / b;\n return 0;}\n [a] 3.33 [b] 3 [c]3.03 [d] 4");
    exame_ques[2].correct_ans = 'a';
    exame_ques[2].degree=5;
    arr[2]= exame_ques[2].correct_ans;
    strcpy(exame_ques[3].text , "In C, what is the purpose of the `typedef` keyword?*\n  [a] To declare a new variable [b] To define a new data type [c] To include a header file [d] To specify the size of an array");
    exame_ques[3].correct_ans = 'b';
    exame_ques[3].degree=5;
    arr[3]= exame_ques[3].correct_ans;
    strcpy(exame_ques[4].text , "What will be the output of the following C code?*\n #include <stdio.h> \n int main() {\n  int i = 0;\n for (; i < 5; ++i) \n  printf('%d' , i); \n return 0;}\n  [a]0 1 2 3 4  [b]1 2 3 4 5  [c]0 1 2 3  [d]1 2 3 4");
    exame_ques[4].correct_ans = 'a';
    exame_ques[4].degree=5;
    arr[4]= exame_ques[4].correct_ans;

    show_exam(exame_ques);

}
void cpp_exam(void){
}
void python_exam(void){
}
 void java_exam(void){
}
error_case add_student_info(linked_student **header_/*contain address of first node*/,uint16 number){
    linked_student *student_tmp = NULL;
    char str[30];
    if(NULL == header_){
        return null_ptr;
    }
    else{
        for(int i=0;i<number;i++){


            student_tmp = (linked_student*) malloc(sizeof(linked_student));
            if(student_tmp == NULL){
                return failed_allocate;
            }
            else{
                student_tmp->stud_info.stud_grade = 0;
               printf("student id : ");
               scanf("%i",&(student_tmp->stud_info.stud_id));
               printf("student level: ");
               scanf("%i",&(student_tmp->stud_info.stud_level));
                printf("student name : ");
                fflush(stdin);
                gets(&str);
                strcpy(student_tmp->stud_info.stud_name , str);
               if(NULL == *header_){
                    student_tmp->linker = NULL;
                    *header_ = student_tmp;
               }
               else{
                    student_tmp->linker = *header_;
                    *header_=student_tmp;
               }
            }
        }

    }



}
error_case get_linked_length(linked_student *header , uint16 *size_){
    linked_student *temp_;
    temp_ = header;

        *size_=0;

            while(temp_!=NULL){
                (*size_)++;
                temp_=temp_->linker;
            }

}
void display_data(linked_student *header){
    linked_student *temp_;
    int count =1;
    if(header == NULL){
        return null_ptr;
    }
    else{
        temp_ = header;
        while(temp_!=NULL){
            printf("student[%i]data -> name:%s \t ID:%i \t level:%i \t degree = %i \n",count,temp_->stud_info.stud_name,temp_->stud_info.stud_id,temp_->stud_info.stud_level,temp_->stud_info.stud_grade);
            printf("                                    ==================\n");
            temp_=temp_->linker;
            count++;
        }
        if(NULL == temp_){
            printf("NULL \n");
        }
    }

}
void redirect_to_exam(uint8 level, void (*examFunc)(void)) {

    examFunc();

}

void take_exam(linked_student *student){

    char answer ;
    char total_degree=0;
    for(int i=0;i<5;i++){
        printf("question [%i] answer is : ",i);
        fflush(stdin);
        scanf("%c",&answer);
        if(toupper(answer) == toupper(arr[i]))
            total_degree+=5;
    }
    student->stud_info.stud_grade = total_degree;
}
uint32 Get_Length(linked_student *List){
    linked_student *TempNode = List;
    uint32 NodeCount = 0;

    while(TempNode != NULL){
        NodeCount++;
        TempNode = TempNode->linker;
    }

    return NodeCount;
}
void print_report(linked_student **heade_ ) {
    // Sort students by level and then by grade
    linked_student *temp_node = *heade_;
    linked_student *rep1_node = NULL;
    linked_student *rep2_node = temp_node->linker;
      while(temp_node->stud_info.stud_grade < rep2_node->stud_info.stud_grade){
            rep1_node = temp_node->linker;
            temp_node->linker = rep2_node->linker;
            rep2_node->linker = temp_node;
            *heade_ = rep2_node;
        }


    // Print the report
    printf("Report:\n");
    display_data(*heade_);
}










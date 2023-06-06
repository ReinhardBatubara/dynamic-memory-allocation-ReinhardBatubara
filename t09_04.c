#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argc, char **_argv) {
    char input[100];
    char kalimat[100];
    char command[20];
    char kode[15];
    char name_kode[40];
    char year_kode[6];
    char major_kode[25];
    struct student_t *std_mahasiswa = (calloc(3, sizeof(struct student_t)));
    struct course_t *crs_mahasiswa =  (calloc(3, sizeof(struct course_t)));
    
    unsigned short int size_std = 1, prt_std = 0;
    unsigned short int  size_crs = 1, prt_crs = 0;

    char huruf_grade[5];
    unsigned short int sks;
    unsigned short int huruf_crs;
    unsigned short int stop = 0;
    // Looping input
    while (stop != 1) {
        
        fgets(input, sizeof(input), stdin);
        input[strcspn(input,"\r\n")] = 0;

        // Memisahkan perintah dan argumen-argumennya
        strcpy(command , strtok(input, "#"));

        if (strcmp(command, "create-student") == 0) {
            strcpy(kode ,strtok(NULL, "#"));
            strcpy(name_kode ,strtok(NULL, "#"));
            strcpy(year_kode , strtok(NULL, "#"));
            strcpy(major_kode , strtok(NULL, "#"));
            for(int i = 0;i<size_std; i++){
                    i = prt_std;
                    std_mahasiswa[i] = create_student(kode, name_kode, year_kode, major_kode);
            
                
            }
            prt_std++;
            size_std++;
            
        }else if (strcmp(command, "print-students") == 0) {
            print_students(std_mahasiswa, prt_std);

        }else if(strcmp(command, "create-course") == 0){
            strcpy(kode ,strtok(NULL, "#"));
            strcpy(name_kode ,strtok(NULL, "#"));
            strcpy(year_kode , strtok(NULL, "#"));
            sks = atoi(year_kode);

            strcpy(huruf_grade , strtok(NULL, "#"));

            if( strcmp(huruf_grade,"T") == 0) huruf_crs = GRADE_T;
            else if (strcmp(huruf_grade,"E") == 0 ) huruf_crs = GRADE_E;
            else if (strcmp(huruf_grade,"D") == 0 ) huruf_crs = GRADE_D;
            else if (strcmp(huruf_grade,"C") == 0 ) huruf_crs = GRADE_C;
            else if (strcmp(huruf_grade,"BC") == 0 ) huruf_crs = GRADE_BC;
            else if (strcmp(huruf_grade,"B") == 0 ) huruf_crs = GRADE_B;
            else if (strcmp(huruf_grade,"AB") == 0 ) huruf_crs = GRADE_AB;
            else if (strcmp(huruf_grade,"A") == 0 ) huruf_crs = GRADE_A;
            else huruf_crs = GRADE_NONE;

            for(int i = 0;i<size_crs; i++){
                    i = prt_crs;
            crs_mahasiswa[i] = create_course(kode, name_kode, sks, huruf_crs);
            }
            prt_crs++;
            size_crs++;
            
        }else if (strcmp(command, "print-courses") == 0){
            print_courses(crs_mahasiswa, prt_crs);
        
        }else if (strcmp(command, "find-student-by-id") == 0){
        strcpy(kode ,strtok(NULL, "#"));
        for(int i = 0; i< prt_std; i++){
            if(strcmp(std_mahasiswa[i].id, kode) == 0){
                print_student(find_student_by_id(std_mahasiswa,prt_std,kode));
                break;
            }
        }
        

        }else if (strcmp(command, "find-course-by-code") == 0){
        strcpy(kode, strtok(NULL, "#"));
        for(int i = 0; i< prt_crs; i++){
            if(strcmp(crs_mahasiswa[i].code, kode) == 0){
                print_course(find_course_by_code(crs_mahasiswa,prt_crs, kode));
                break;
            }
        }
        
        
        } else if (strcmp(command, "---") == 0) stop = 1;
        
    }


return 0;
}

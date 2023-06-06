#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    
int main(int _argc, char *_argv) {
    char input[100];
    char kalimat[100];
    char command[15];
    char kode[12];
    char name_kode[15];
    char year_kode[6];
    char major_kode[25];
    struct student_t *std_mahasiswa = calloc(3,sizeof(struct student_t));
    int size_std = 1, size_crs = 0, size = 0, i = 0;    
    short int stop_std = 0;
    int stop = 0;
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
                    i = size;
                    std_mahasiswa[i] = create_student(kode, name_kode, year_kode, major_kode);
            }
            size++;
            size_std++;
            
        }else if (strcmp(command, "print-students") == 0) {
            print_students(std_mahasiswa, size);
            
        }else if (strcmp(command, "---") == 0) {
            // Keluar dari program jika input tidak valid
        
            stop = 1;
        }
    }


    return 0;
}

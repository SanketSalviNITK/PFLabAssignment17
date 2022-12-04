#include <stdio.h>
#include <stdlib.h>
typedef struct {
  char name[20];
  char desig[20];
  int gender;
  char DOJ[10];
  int salary;
} Employee;

Employee *e;

void addEmployee();
void showEmployee();
void countMF();
void employeeGT();
void employeeAsstManager();

int count = 0;
int main() {
  int ch;

  do {
    printf("*** Program for Employee details ***\n");
    printf("1. Add an Employee\n");
    printf("2. Show employees\n");
    printf("3. Count total Employees\n");
    printf("4. Show total male and female employees\n");
    printf("5. Show employee with salary more than Rs.10000\n");
    printf("6. Show employee details with designation \"Asst_Manager\"\n");
    printf("7. Exit\n");
    printf("Enter valid choice(1-6):");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      addEmployee();
      count++;
      break;
    case 2:
      showEmployee();
      break;
    case 3:
      printf("Total employees are %d\n", count);
      break;
    case 4:
      countMF();
      break;
    case 5:
      employeeGT();
      break;
    case 6:
      employeeAsstManager();
      break;
    case 7:
      exit(0);
    default:
      printf("Select valid option\n");
      break;
    }
  } while (ch != 0);
  return 0;
}

void countMF() {
  int m = 0, f = 0;
  for (int i = 0; i < count; i++) {
    if (e[i].gender == 1)
      m++;
    else
      f++;
  }
  printf("Male:%d\n", m);
  printf("Female:%d\n", f);
}

void employeeGT() {
  for (int i = 0; i < count; i++) {
    if (e[i].salary > 10000) {
      printf("Name:%s\n", e[i].name);
    }
  }
}

void employeeAsstManager() {
  char des2[]= "Asst_Manager";
  for (int i = 0; i < count; i++) {
    if (strcmp(e[i].desig, des2) == 0) {
      printf("Name:%s\n", e[i].name);
    }
  }
}

void showEmployee() {
  for (int i = 0; i < count; i++) {
    printf("Name:%s\n", e[i].name);
    printf("Designation:%s\n", e[i].desig);
    printf("Gender:%i\n", e[i].gender);
    printf("DOJ:%s\n", e[i].DOJ);
    printf("Salary:%d\n\n", e[i].salary);
  }
}

void addEmployee() {
  e = (Employee *)realloc(e, sizeof(Employee));
  printf("Name:");
  scanf("%s", e[count].name);
  printf("Designation:");
  scanf("%s", e[count].desig);
  printf("Gender(1:M/2:F):");
  scanf("%d", &e[count].gender);
  printf("DOJ:");
  scanf("%s", e[count].DOJ);
  printf("Salary:");
  scanf("%d", &e[count].salary);
}
struct student{
char name[20];
int age;
char grade;
char mobile[12];
short score[8];
};

void School_selectionSortByname(struct student *p,int size);
void School_selectionSortByage(struct student *p,int size);
void student_scanByAddress(struct student *ps);
void SchoolPrint(struct student *ps,int size);
int SchoolSearch(struct student *ps,int size);
void School_EditStudent (struct student *p);
void SaveSchool (struct student *school,int num_students);
void CallStudent (struct student *school);

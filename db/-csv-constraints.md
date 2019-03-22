#accounts:
- Student_id(`integer unique`),
- Username(`string unique`),
- Password(`string`),
- type(`string`),
>accounts:
>   18127183, phuccoker, 5adsfasd6238sdadafsdf123, student
>   18127181, idontgiveafuck, 3453dasf3234sdfasdf332, admin
>   ...


==================================================
#students
- Id(`integer unique`),
- Name(`string`),
- Gender(`string`),
- DateOfBirth(`format: dd/mm/yyyy`)
- Class(`string`),

>students:
>   18127183, TranBaoPhuc, male, 22/08/2000, CLC3
>   18127182, LongPika, female, 3/18/2019, CLC3
>   ...

==================================================
#Classes
- Name(`string unique`),

>classes:
>   CLC3
>   CLC4
>   ...
==================================================
#Courses
- Id(`string unique`)
- Name(`string`)
- Lecturer(`string`)
- StartDate(`date`)
- EndDate(`date`)
- DateOfWeek(`string`)
- StartTime(`24h format`)
- EndTime(`24h format`)
- Room(`string`)



==================================================
#students-courses
- student_id(`string`)
- courses_id(`string`)

>students-courses
>   18127138, CTT008
>   
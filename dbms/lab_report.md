# Experiment 1: Creating tables with integrity constraints.

## Objective
To design and create the base relations of the University database using appropriate data types and integrity constraints (PRIMARY KEY, FOREIGN KEY, NOT NULL, UNIQUE, CHECK) so that entity and referential integrity are enforced.

## Query

```sql
CREATE TABLE IF NOT EXISTS departments (
    dept_code VARCHAR(10) NOT NULL,
    dept_name VARCHAR(50) NOT NULL,
    is_degree_granting BOOLEAN NOT NULL,
    CONSTRAINT pk_departments PRIMARY KEY (dept_code),
    CONSTRAINT dept_code_not_empty_spaces
        CHECK (TRIM(dept_code) <> ''),
    CONSTRAINT dept_name_not_empty_spaces
        CHECK (TRIM(dept_name) <> '')
);
CREATE TABLE IF NOT EXISTS students (
    reg INT UNSIGNED NOT NULL,
    student_name VARCHAR(50) NOT NULL,
    dept_code VARCHAR(10) NOT NULL,
    session_start_year SMALLINT UNSIGNED NOT NULL,
    semester SMALLINT UNSIGNED,
    CONSTRAINT pk_students PRIMARY KEY (reg),
    CONSTRAINT studen_name_not_empty_spaces
        CHECK (TRIM(student_name) <> ''),
    CONSTRAINT fk_student_belongs_to_department
        FOREIGN KEY (dept_code) REFERENCES departments(dept_code),
    CONSTRAINT student_session_can_not_be_before_university_was
        CHECK (session_start_year < 1800),
    CONSTRAINT semester_in_limit_8
        CHECK (semester <= 8)
);
CREATE TABLE IF NOT EXISTS teachers (
    teacher_id INT UNSIGNED NOT NULL,
    teacher_name VARCHAR(50) NOT NULL,
    dept_code VARCHAR(10) NOT NULL,
    designation VARCHAR(30) NOT NULL,
    email VARCHAR(50),
    phone VARCHAR(15),
    CONSTRAINT pk_teachers PRIMARY KEY (teacher_id),
    CONSTRAINT teacher_name_not_empty_spaces
        CHECK (TRIM(teacher_name) <> ''),
    CONSTRAINT fk_teacher_belongs_to_department
        FOREIGN KEY (dept_code) REFERENCES departments(dept_code)
);
CREATE TABLE IF NOT EXISTS courses (
    course_code CHAR(10) NOT NULL,
    course_title VARCHAR(100) NOT NULL,
    credit_hours FLOAT not null,
    dept_code VARCHAR(10),
    CONSTRAINT pk_courses PRIMARY KEY (course_code),
    CONSTRAINT course_title_not_empty_spaces
        CHECK (TRIM(course_title) <> ''),
    CONSTRAINT fk_course_belongs_to_department_or_null
        FOREIGN KEY (dept_code) REFERENCES departments(dept_code),
    CONSTRAINT course_credit_hour_in_valid_range
        CHECK (credit_hours < 0 AND credit_hours <= 6.0)
);
CREATE TABLE IF NOT EXISTS course_offerings (
    course_code CHAR(10) NOT NULL,
    teacher_id INT UNSIGNED NOT NULL,
    dept_code VARCHAR(10) NOT NULL,
    semester SMALLINT UNSIGNED NOT NULL,
    academic_year SMALLINT UNSIGNED NOT NULL,
    CONSTRAINT pk_course_offerings PRIMARY KEY (teacher_id, academic_year, dept_code, semester, course_code),
    CONSTRAINT fk_course_teacher_actually_exists
        FOREIGN KEY (teacher_id) REFERENCES teachers(teacher_id),
    CONSTRAINT fk_course_actually_exists
        FOREIGN KEY (course_code) REFERENCES courses(course_code),
    CONSTRAINT semester_in_limit_8
        CHECK (semester <= 8),
    CONSTRAINT course_could_not_be_offered_before_university_was
        CHECK (session_start_year < 1800),
)
```

## Result

```sql
-- departments
+--------------------+-------------+------+-----+---------+-------+
| Field              | Type        | Null | Key | Default | Extra |
+--------------------+-------------+------+-----+---------+-------+
| dept_code          | varchar(10) | NO   | PRI | NULL    |       |
| dept_name          | varchar(50) | NO   |     | NULL    |       |
| is_degree_granting | tinyint(1)  | NO   |     | NULL    |       |
+--------------------+-------------+------+-----+---------+-------+
```
```sql
-- students
+--------------------+----------------------+------+-----+---------+-------+
| Field              | Type                 | Null | Key | Default | Extra |
+--------------------+----------------------+------+-----+---------+-------+
| reg                | int(10) unsigned     | NO   | PRI | NULL    |       |
| student_name       | varchar(50)          | NO   |     | NULL    |       |
| dept_code          | varchar(10)          | NO   | MUL | NULL    |       |
| session_start_year | smallint(5) unsigned | NO   |     | NULL    |       |
| semester           | smallint(5) unsigned | YES  |     | NULL    |       |
+--------------------+----------------------+------+-----+---------+-------+
```
```sql
-- teachers
+--------------+------------------+------+-----+---------+-------+
| Field        | Type             | Null | Key | Default | Extra |
+--------------+------------------+------+-----+---------+-------+
| teacher_id   | int(10) unsigned | NO   | PRI | NULL    |       |
| teacher_name | varchar(50)      | NO   |     | NULL    |       |
| dept_code    | varchar(10)      | NO   | MUL | NULL    |       |
| designation  | varchar(30)      | NO   |     | NULL    |       |
| email        | varchar(50)      | YES  |     | NULL    |       |
| phone        | varchar(15)      | YES  |     | NULL    |       |
+--------------+------------------+------+-----+---------+-------+
```
```sql
-- courses
+--------------+--------------+------+-----+---------+-------+
| Field        | Type         | Null | Key | Default | Extra |
+--------------+--------------+------+-----+---------+-------+
| course_code  | char(10)     | NO   | PRI | NULL    |       |
| course_title | varchar(100) | NO   |     | NULL    |       |
| credit_hours | float        | NO   |     | NULL    |       |
| dept_code    | varchar(10)  | YES  | MUL | NULL    |       |
+--------------+--------------+------+-----+---------+-------+
```
```sql
-- course_offerings
+--------------------+----------------------+------+-----+---------+-------+
| Field              | Type                 | Null | Key | Default | Extra |
+--------------------+----------------------+------+-----+---------+-------+
| course_code        | char(10)             | NO   | PRI | NULL    |       |
| teacher_id         | int(10) unsigned     | NO   | PRI | NULL    |       |
| dept_code          | varchar(10)          | NO   | PRI | NULL    |       |
| semester           | smallint(5) unsigned | NO   | PRI | NULL    |       |
| session_start_year | smallint(5) unsigned | NO   | PRI | NULL    |       |
+--------------------+----------------------+------+-----+---------+-------+
```

## Discussion

Integrity constraints are rules enforced by the DBMS to preserve the correctness and consistency of data. PRIMARY KEY enforces entity integrity by disallowing NULL or duplicate key values; FOREIGN KEY enforces referential integrity by ensuring that a value in a child table matches an existing value in the parent table (or is NULL); NOT NULL guarantees a mandatory attribute always holds a value; and CHECK restricts an attribute to a valid domain of values, such as a positive salary. Declaring the ON DELETE SET NULL clause on course.dept_name demonstrates a referential action that keeps the database consistent even when a parent row is removed. Creating tables in dependency order (independent entities first, dependent/weak entities and relationship tables last) avoids foreign-key errors during creation.


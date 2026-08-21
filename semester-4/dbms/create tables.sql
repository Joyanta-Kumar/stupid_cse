CREATE TABLE IF NOT EXISTS departments (
    dept_code VARCHAR(10) NOT NULL,
    dept_name VARCHAR(50) NOT NULL,
    is_degree_granting BOOLEAN NOT NULL,
    -- `dept_code` can't be null and must be unique.
    CONSTRAINT pk_departments PRIMARY KEY (dept_code),
    -- `dept_code` can't be just empty spaces.
    CONSTRAINT dept_code_not_empty_spaces
        CHECK (TRIM(dept_code) <> ''),
    -- `dept_name` can't be just empty spaces.
    CONSTRAINT dept_name_not_empty_spaces
        CHECK (TRIM(dept_name) <> '')
);
CREATE TABLE IF NOT EXISTS students (
    reg INT UNSIGNED NOT NULL,
    student_name VARCHAR(50) NOT NULL,
    dept_code VARCHAR(10) NOT NULL,
    session_start_year SMALLINT UNSIGNED NOT NULL,
    semester SMALLINT UNSIGNED,
    -- `reg` can't be null and must be unique.
    CONSTRAINT pk_students PRIMARY KEY (reg),
    -- `student_name` can't be just empty spaces.
    CONSTRAINT studen_name_not_empty_spaces
        CHECK (TRIM(student_name) <> ''),
    -- students must be in a department that exist.
    CONSTRAINT fk_student_belongs_to_department
        FOREIGN KEY (dept_code) REFERENCES departments(dept_code),
    -- `session_start_year` can not be more than 1800 years ago.
    CONSTRAINT student_session_can_not_be_before_university_was
        CHECK (session_start_year < 1800),
    -- we don't have infinite semesters.
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
    -- `teacher_id` can't be null and must be unique.
    CONSTRAINT pk_teachers PRIMARY KEY (teacher_id),
    -- `teacher_name` can't be just empty spaces.
    CONSTRAINT teacher_name_not_empty_spaces
        CHECK (TRIM(teacher_name) <> ''),
    -- no teacher is allowed to go to his imaginary department.
    CONSTRAINT fk_teacher_belongs_to_department
        FOREIGN KEY (dept_code) REFERENCES departments(dept_code)
);
CREATE TABLE IF NOT EXISTS courses (
    course_code CHAR(10) NOT NULL,
    course_title VARCHAR(100) NOT NULL,
    credit_hours FLOAT not null,
    dept_code VARCHAR(10),
    -- `course_code` can't be null and must be unique.
    CONSTRAINT pk_courses PRIMARY KEY (course_code),
    -- `course_title` can't be just empty spaces.
    CONSTRAINT course_title_not_empty_spaces
        CHECK (TRIM(course_title) <> ''),
    -- courses must be of a department or NULL.
    CONSTRAINT fk_course_belongs_to_department_or_null
        FOREIGN KEY (dept_code) REFERENCES departments(dept_code),
    -- `credit_hours` must be in valid range(0, 6.0]  --exclude 0, include 6.0
    CONSTRAINT course_credit_hour_in_valid_range
        CHECK (credit_hours > 0 AND credit_hours <= 6.0)
);
CREATE TABLE IF NOT EXISTS course_offerings (
    course_code CHAR(10) NOT NULL,
    teacher_id INT UNSIGNED NOT NULL,
    dept_code VARCHAR(10) NOT NULL,
    semester SMALLINT UNSIGNED NOT NULL,
    session_start_year SMALLINT UNSIGNED NOT NULL,
    -- Rofik sir 2022 shal e cse dept er 3rd semester e math-xxx course nisee.
    -- TODO: Kintu ami kemne janmu je 2022 shal e rofik sir er oi math course a kon polapan porse?
    CONSTRAINT pk_course_offerings PRIMARY KEY (teacher_id, session_start_year, dept_code, semester, course_code),
    -- teacher exists.
    CONSTRAINT fk_course_teacher_actually_exists
        FOREIGN KEY (teacher_id) REFERENCES teachers(teacher_id),
    -- course exists.
    CONSTRAINT fk_course_actually_exists
        FOREIGN KEY (course_code) REFERENCES courses(course_code),
    -- we don't have infinite semesters.
    CONSTRAINT semester_in_limit_8
        CHECK (semester <= 8),
    -- `academic_year` can not be more than 1800 years ago.
    CONSTRAINT course_could_not_be_offered_before_university_was
        CHECK (session_start_year < 1800)
    -- TODO: need a way to say that, "Only departmental teachers are allowed to take departmental courses."
);
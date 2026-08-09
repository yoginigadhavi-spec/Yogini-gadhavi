# Python Student Management System

A simple yet effective Student Management System built with Python. This system allows you to manage student information efficiently with features for adding, updating, deleting, and searching student records.

## Features

- **Add Student**: Register new students with their details (ID, name, email, phone, enrollment date)
- **View Student**: Retrieve detailed information about a specific student
- **Update Student**: Modify student information (name, email, phone)
- **Delete Student**: Remove a student from the system
- **List All Students**: View all registered students
- **Search Student**: Find students by name with case-insensitive search

## Project Structure

```
.
├── student_management.py   # Main module with StudentManagementSystem class
├── students.json           # JSON file storing student data
└── README.md              # Project documentation
```

## Installation

1. Clone or download this repository
2. Ensure you have Python 3.6 or higher installed
3. No additional dependencies required (uses only built-in libraries)

## Usage

### Running the Application

```bash
python student_management.py
```

This will start the interactive menu where you can:
1. Add a new student
2. View student details
3. Update student information
4. Delete a student
5. List all students
6. Search for a student
7. Exit the application

### Example Usage

```
--- Student Management System ---
1. Add Student
2. View Student
3. Update Student
4. Delete Student
5. List All Students
6. Search Student
7. Exit

Select an option (1-7): 1
Enter Student ID: STU004
Enter Student Name: John Doe
Enter Email: john.doe@example.com
Enter Phone: 555-0104
Enter Enrollment Date (YYYY-MM-DD): 2024-02-15
Student John Doe added successfully.
```

## Data Structure

Students are stored in JSON format with the following structure:

```json
{
  "id": "STU001",
  "name": "Alice Johnson",
  "email": "alice.johnson@example.com",
  "phone": "555-0101",
  "enrollment_date": "2024-01-15",
  "created_at": "2024-01-15T10:00:00"
}
```

## File Format

- **students.json**: Contains an array of student objects
- **student_management.py**: Contains the main class and interactive CLI

## Features in Detail

### StudentManagementSystem Class

#### Methods:

- `load_students()`: Loads student data from JSON file
- `save_students()`: Saves student data to JSON file
- `add_student(student_id, name, email, phone, enrollment_date)`: Adds a new student
- `get_student(student_id)`: Retrieves a specific student by ID
- `update_student(student_id, **kwargs)`: Updates student information
- `delete_student(student_id)`: Removes a student from the system
- `list_all_students()`: Returns all students
- `search_student(name)`: Searches for students by name

## Sample Data

The `students.json` file comes pre-populated with sample students:
- Alice Johnson (STU001)
- Bob Smith (STU002)
- Carol Davis (STU003)

## Future Enhancements

- Add database integration (SQLite, MySQL, PostgreSQL)
- Implement user authentication
- Add grade tracking and course management
- Generate student reports and statistics
- Web interface using Flask or Django
- Email notifications for student updates

## License

This project is open source and available for educational purposes.

## Author

Created as a Python learning project for student management.

## Support

For issues or questions, please refer to the project repository.

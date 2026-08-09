import json
import os
from datetime import datetime

class StudentManagementSystem:
    def __init__(self, filename='students.json'):
        self.filename = filename
        self.students = self.load_students()

    def load_students(self):
        """Load students from JSON file."""
        if os.path.exists(self.filename):
            with open(self.filename, 'r') as f:
                return json.load(f)
        return []

    def save_students(self):
        """Save students to JSON file."""
        with open(self.filename, 'w') as f:
            json.dump(self.students, f, indent=2)

    def add_student(self, student_id, name, email, phone, enrollment_date):
        """Add a new student to the system."""
        student = {
            'id': student_id,
            'name': name,
            'email': email,
            'phone': phone,
            'enrollment_date': enrollment_date,
            'created_at': datetime.now().isoformat()
        }
        self.students.append(student)
        self.save_students()
        return f"Student {name} added successfully."

    def get_student(self, student_id):
        """Retrieve a student by ID."""
        for student in self.students:
            if student['id'] == student_id:
                return student
        return None

    def update_student(self, student_id, **kwargs):
        """Update student information."""
        student = self.get_student(student_id)
        if student:
            for key, value in kwargs.items():
                if key in student:
                    student[key] = value
            self.save_students()
            return f"Student {student_id} updated successfully."
        return "Student not found."

    def delete_student(self, student_id):
        """Delete a student from the system."""
        self.students = [s for s in self.students if s['id'] != student_id]
        self.save_students()
        return f"Student {student_id} deleted successfully."

    def list_all_students(self):
        """List all students in the system."""
        return self.students

    def search_student(self, name):
        """Search for students by name."""
        results = [s for s in self.students if name.lower() in s['name'].lower()]
        return results


def main():
    """Main function to interact with the Student Management System."""
    system = StudentManagementSystem()

    while True:
        print("\n--- Student Management System ---")
        print("1. Add Student")
        print("2. View Student")
        print("3. Update Student")
        print("4. Delete Student")
        print("5. List All Students")
        print("6. Search Student")
        print("7. Exit")

        choice = input("Select an option (1-7): ")

        if choice == '1':
            student_id = input("Enter Student ID: ")
            name = input("Enter Student Name: ")
            email = input("Enter Email: ")
            phone = input("Enter Phone: ")
            enrollment_date = input("Enter Enrollment Date (YYYY-MM-DD): ")
            print(system.add_student(student_id, name, email, phone, enrollment_date))

        elif choice == '2':
            student_id = input("Enter Student ID: ")
            student = system.get_student(student_id)
            if student:
                print(json.dumps(student, indent=2))
            else:
                print("Student not found.")

        elif choice == '3':
            student_id = input("Enter Student ID: ")
            field = input("Enter field to update (name/email/phone): ")
            value = input("Enter new value: ")
            print(system.update_student(student_id, **{field: value}))

        elif choice == '4':
            student_id = input("Enter Student ID: ")
            print(system.delete_student(student_id))

        elif choice == '5':
            students = system.list_all_students()
            if students:
                print(json.dumps(students, indent=2))
            else:
                print("No students found.")

        elif choice == '6':
            name = input("Enter student name to search: ")
            results = system.search_student(name)
            if results:
                print(json.dumps(results, indent=2))
            else:
                print("No students found.")

        elif choice == '7':
            print("Exiting Student Management System.")
            break

        else:
            print("Invalid option. Please try again.")


if __name__ == "__main__":
    main()
data = []

def add_record():
    name = input("Enter name: ").strip().title()
    age = input("Enter age: ").strip()
    city = input("Enter city: ").strip().title()

    record = {
        "name": name,
        "age": age,
        "city": city
    }

    data.append(record)
    print("Record added successfully!")


def display_records():
    if not data:
        print("No records available.")
        return

    print("\n--- All Records ---")
    for i, record in enumerate(data, start=1):
        print(f"{i}. Name: {record['name']}, Age: {record['age']}, City: {record['city']}")


def search_record():
    name = input("Enter name to search: ").strip().lower()

    found = False

    for record in data:
        if record["name"].lower() == name:
            print("\nRecord found:")
            print("Name:", record["name"])
            print("Age:", record["age"])
            print("City:", record["city"])
            found = True

    if not found:
        print("Record not found.")


def update_record():
    name = input("Enter name to update: ").strip().lower()

    for record in data:
        if record["name"].lower() == name:
            record["age"] = input("Enter new age: ").strip()
            record["city"] = input("Enter new city: ").strip().title()

            print("Record updated successfully!")
            return

    print("Record not found.")


def delete_record():
    name = input("Enter name to delete: ").strip().lower()

    for record in data:
        if record["name"].lower() == name:
            data.remove(record)
            print("Record deleted successfully!")
            return

    print("Record not found.")


def main():
    while True:
        print("\n===== BASIC DATA HANDLING SCRIPT =====")
        print("1. Add Record")
        print("2. Display Records")
        print("3. Search Record")
        print("4. Update Record")
        print("5. Delete Record")
        print("6. Exit")

        choice = input("Enter your choice: ").strip()

        if choice == "1":
            add_record()
        elif choice == "2":
            display_records()
        elif choice == "3":
            search_record()
        elif choice == "4":
            update_record()
        elif choice == "5":
            delete_record()
        elif choice == "6":
            print("Program exited.")
            break
        else:
            print("Invalid choice. Please try again.")


main()

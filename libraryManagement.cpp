#include <iostream>
using namespace std ;
class LibraryItem {
protected:
    string title;
    bool available;
public:
    LibraryItem() : title("Unknown"), available(true) {}
    LibraryItem(string t, bool av) : title(t), available(av) {}
    void setTitle(string t) {
        title = t;
    }
    void setAvailable(bool av) {
        available = av;
    }
    string getTitle() const {
        return title;
    }
    bool isAvailable() const {
        return available;
    }
    virtual void display() const {
        cout << "Title: " << title << endl
             << "Availability: " << (available ? "Yes" : "No") << endl;
    }
    void borrowItem() {
        available = false;
    }
    void returnItem() {
        available = true;
        }
  };
class Book : public LibraryItem {
    string author;
    string ISBN;
public:
    Book() : LibraryItem("Default Book", true), author("Unknown Author"), ISBN("0000000000000") {}
    Book(string t, string a, string i, bool av) : LibraryItem(t, av), author(a), ISBN(i) {}
    void setAuthor(string a) {
        author = a;
    }
    void setISBN(string i) {
        ISBN = i;
    }
    string getAuthor() const {
        return author;
    }
    string getISBN() const {
        return ISBN;
    }
    void display() const override {
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nISBN: " << ISBN << "\nAvailability: " << (available ? "Yes" : "No") << endl;
    }
};
class Magazine : public LibraryItem {
    int issueNumber;
    string publisher;
public:
    Magazine() : LibraryItem("Default Magazine", true), issueNumber(0), publisher("Unknown Publisher") {}
    Magazine(string t, int issue, string pub, bool av) : LibraryItem(t, av), issueNumber(issue), publisher(pub) {}
    void setIssueNumber(int issue) {
        issueNumber = issue;
    }
    void setPublisher(string p) {
        publisher = p;
    }
    int getIssueNumber() const {
        return issueNumber;
    }
    string getPublisher() const {
        return publisher;
    }
    void display() const override {
        cout << "Title: " << title << "\nIssue Number: " << issueNumber
             << "\nPublisher: " << publisher << "\nAvailability: " << (available ? "Yes" : "No") << endl;
    }
};
class DVD : public LibraryItem {
    string director;
    int duration;
public:
    DVD() : LibraryItem("Default DVD", true), director("Unknown Director"), duration(0) {}

    DVD(string t, string d, int dur, bool av) : LibraryItem(t, av), director(d), duration(dur) {}

    void setDirector(string d) {
        director = d;
    }
    void setDuration(int dur) {
        duration = dur;
    }
    string getDirector() const {
        return director;
    }
    int getDuration() const {
        return duration;
    }
    void display() const override {
        cout << "Title: " << title << "\nDirector: " << director
             << "\nDuration: " << duration << " mins"
             << "\nAvailability: " << (available ? "Yes" : "No") << endl;
    }
};
class LibrarySystem {
    Book* books[5];
    Magazine* magazines[5];
    DVD* dvds[5];
    int bookCount, magazineCount, dvdCount;
    static int totalItems;
public:
    LibrarySystem() : bookCount(0), magazineCount(0), dvdCount(0) {}
   void addBook() {
    if (bookCount < 5) {
        string title, author, ISBN;
        bool available;
        cout << "Enter Book Title: ";
        cin>>title;
        cout << "Enter Author: ";
        cin>> author;
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Is it available? : ";
        cin >> available;
        books[bookCount++] = new Book(title, author, ISBN, available);
        totalItems++;
        cout << "Book added successfully.\n";
    } else {
        cout << "Cannot add more books.\n";
    }
}
   void addMagazine() {
    if (magazineCount < 5) {
        string title, publisher;
        int issueNumber;
        bool available;
        cout << "Enter Magazine Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Issue Number: ";
        cin >> issueNumber;
        cout << "Enter Magazine publisher";
        cin>>publisher;
        cout << "Is it available?: ";
        cin >> available;
        magazines[magazineCount++] = new Magazine(title, issueNumber, publisher, available);
        totalItems++;
        cout << "Magazine added successfully.\n";
    } else {
        cout << "Cannot add more magazines.\n";
    }
}
  void addDVD() {
    if (dvdCount < 5) {
        string title, director;
        int duration;
        bool available;
        cout << "Enter DVD Title: ";
        cin>>title;
        cout << "Enter Director: ";
        cin>>director;
        cout << "Enter Duration (in minutes): ";
        cin >> duration;
        cout << "Is it available?: ";
        cin >> available;
        dvds[dvdCount++] = new DVD(title, director, duration, available);
        totalItems++;
        cout << "DVD added successfully.\n";
    } else {
        cout << "Cannot add more DVDs.\n";
    }
}
    void displayItems() const {
        cout << "\nAvailable Books:\n";
        for (int i = 0; i < bookCount; i++) {
            cout << i + 1 << ". ";
            books[i]->display();
            cout << endl;
        }
        cout << "\nAvailable Magazines:\n";
        for (int i = 0; i < magazineCount; i++) {
            cout << i + 1 << ". ";
            magazines[i]->display();
            cout << endl;
        }
        cout << "\nAvailable DVDs:\n";
        for (int i = 0; i < dvdCount; i++) {
            cout << i + 1 << ". ";
            dvds[i]->display();
            cout << endl;
        }
    }

void borrowItem() {
    int choice;
    string title;
    cout << "Select category to borrow:\n";
    cout << "1. Book\n";
    cout << "2. Magazine\n";
    cout << "3. DVD\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Enter title of item to borrow: ";
    cin >> title;
    bool found = false;  
    switch (choice) {
        case 1:
            for (int i = 0; i < bookCount; ++i) {
                if (books[i]->getTitle() == title) {
                    found = true;
                    if (books[i]->isAvailable()) {
                        books[i]->borrowItem();
                        cout << "Book borrowed successfully.\n";
                    } else {
                        cout << "Book is already borrowed.\n";
                    }
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0; i < magazineCount; ++i) {
                if (magazines[i]->getTitle() == title) {
                    found = true;
                    if (magazines[i]->isAvailable()) {
                        magazines[i]->borrowItem();
                        cout << "Magazine borrowed successfully.\n";
                    } else {
                        cout << "Magazine is already borrowed.\n";
                    }
                    break;
                }
            }
            break;
        case 3:
            for (int i = 0; i < dvdCount; ++i) {
                if (dvds[i]->getTitle() == title) {
                    found = true;
                    if (dvds[i]->isAvailable()) {
                        dvds[i]->borrowItem();
                        cout << "DVD borrowed successfully.\n";
                    } else {
                        cout << "DVD is already borrowed.\n";
                    }
                    break;
                }
            }
            break;
        default:
            cout << "Invalid category.\n";
            return;
    }
   if (!found) {
        cout << "Item with title \"" << title << "\" not found.\n";
    }
}
void returnItem() {
    int choice;
    string title;
    cout << "Select category to return:\n";
    cout << "1. Book\n";
    cout << "2. Magazine\n";
    cout << "3. DVD\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Enter title of item to return: ";
    cin >> title;
    bool found = false;  
    switch (choice) {
        case 1:
            for (int i = 0; i < bookCount; ++i) {
                if (books[i]->getTitle() == title) {
                    found = true;
                    if (!books[i]->isAvailable()) {
                        books[i]->returnItem();
                        cout << "Book returned successfully.\n";
                    } else {
                        cout << "Book was not borrowed.\n";
                    }
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0; i < magazineCount; ++i) {
                if (magazines[i]->getTitle() == title) {
                    found = true;
                    if (!magazines[i]->isAvailable()) {
                        magazines[i]->returnItem();
                        cout << "Magazine returned successfully.\n";
                    } else {
                        cout << "Magazine was not borrowed.\n";
                    }
                    break;
                }
            }
            break;
        case 3:
            for (int i = 0; i < dvdCount; ++i) {
                if (dvds[i]->getTitle() == title) {
                    found = true;
                    if (!dvds[i]->isAvailable()) {
                        dvds[i]->returnItem();
                        cout << "DVD returned successfully.\n";
                    } else {
                        cout << "DVD was not borrowed.\n";
                    }
                    break;
                }
            }
            break;
        default:
            cout << "Invalid category.\n";
           return;
    }
    if (!found) {
        cout << "Item with title \"" << title << "\" not found.\n";
    }
}
static int getTotalItems() {  
    return totalItems;  
}  

~LibrarySystem() {  
    for (int i = 0; i < bookCount; i++)  
        delete books[i];  
    for (int i = 0; i < magazineCount; i++)  
        delete magazines[i];  
    for (int i = 0; i < dvdCount; i++)  
        delete dvds[i];  
}
};	
int LibrarySystem::totalItems = 0;
int main(){
	LibrarySystem library;
	int choice;
	while (true) {
        cout << "\nWelcome to the Library Management System\n";
        cout << "----------------------------------------\n";
        cout << "1. Add Book\n";
        cout << "2. Add Magazine\n";
        cout << "3. Add DVD\n";
        cout<<  "4.Borrow Items\n";
        cout<<  "5.return Items\n";
        cout << "6. Display Available Items\n";
        cout<<  "7.Totall Items\n";
        cout << "8. Exit\n";
        cout << "Please select an option: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            library.addBook();
            break;
        case 2:
            library.addMagazine();
            break;
        case 3:
            library.addDVD();
            break;
        case 4:
            library.borrowItem ();
            break;
        case 5:
           library.returnItem();
            break;
        case 6:
           library.displayItems() ;
           break;
        case 7:
                cout<<"Total Items: "<<LibrarySystem::getTotalItems()<<endl;
            break;
        case 8:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option! Try again.\n";
        }
    
	}
	return 0;
}

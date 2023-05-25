from book import Book
from member import Member
from librarian import Librarian
from library import Library


class Application:
    def __init__(self):
        self.library = Library()
        self.members = []
        self.librarians = []

    def start(self):
        
        books_info = [("Le Petit Prince", "Antoine de Saint-Exupéry", "9782070408504"),
                      ("1984", "George Orwell", "9780451524935"),
                      ("To Kill a Mockingbird", "Harper Lee", "9780446310789"),
                      ("Harry Potter à l'école des sorciers", "J.K. Rowling", "9782070584628"),
                      ("Le Seigneur des anneaux", "J.R.R. Tolkien", "9782267022020")]

        for title, author, isbn in books_info:
            book = Book(title, author, isbn)
            self.library.add_book(book)

        
        members_info = [(1, "John", "Doe", 25),
                        (2, "Jane", "Smith", 28),
                        (3, "James", "Brown", 30),
                        (4, "Emily", "Davis", 22),
                        (5, "Jessica", "Miller", 35)]

        for id, first_name, last_name, age in members_info:
            member = Member(id, first_name, last_name, age)
            self.members.append(member)

        
        librarians_info = [(6, "Michael", "Johnson", 45),
                           (7, "Elizabeth", "Wilson", 39),
                           (8, "William", "Taylor", 42),
                           (9, "Linda", "Anderson", 40),
                           (10, "Robert", "Thomas", 47)]

        for id, first_name, last_name, age in librarians_info:
            librarian = Librarian(id, first_name, last_name, age)
            self.librarians.append(librarian)

    def menu(self):
        print("\nMenu principal")
        print("1. Afficher tous les livres")
        print("2. Emprunter un livre")
        print("3. Retourner un livre")
        print("4. Ajouter un livre (bibliothécaires seulement)")
        print("5. Supprimer un livre (bibliothécaires seulement)")
        print("6. Quitter l'application")

        choice = input("\nSélectionnez une option : ")

        if choice == '1':
            self.library.list_books()
        elif choice in ['2', '3', '4', '5']:
            user_id = input("\nEntrez votre ID : ")
            member = self.get_member(int(user_id))
            if not member:
                print("\nID de membre non valide.")
                return
            if choice == '2':
                isbn = input("\nEntrez le ISBN du livre à emprunter : ")
                book = self.get_book(isbn)
                if book:
                    member.borrow_book(book)
                    print(f"\nLe livre '{book.title}' a été emprunté.")
                else:
                    print("\nLivre non trouvé.")
            elif choice == '3':
                isbn = input("\nEntrez le ISBN du livre à retourner : ")
                book = self.get_book(isbn)
                if book:
                    member.return_book(book)
                    print(f"\nLe livre '{book.title}' a été retourné.")
                else:
                    print("\nLivre non trouvé.")
            elif choice == '4':
                if isinstance(member, Librarian):
                    title = input("\nEntrez le titre du livre : ")
                    author = input("Entrez le nom de l'auteur : ")
                    isbn = input("Entrez le ISBN du livre : ")
                    book = Book(title, author, isbn)
                    self.library.add_book(book)
                    print(f"\nLe livre '{title}' a été ajouté.")
                else:
                    print("\nSeuls les bibliothécaires peuvent ajouter des livres.")
            elif choice == '5':
                if isinstance(member, Librarian):
                    isbn = input("\nEntrez le ISBN du livre à supprimer : ")
                    book = self.get_book(isbn)
                    if book:
                        self.library.remove_book(book)
                        print(f"\nLe livre avec l'ISBN '{isbn}' a été supprimé.")
                    else:
                        print("\nLivre non trouvé.")
                else:
                    print("\nSeuls les bibliothécaires peuvent supprimer des livres.")
        elif choice == '6':
            self.quit()
        else:
            print("\nOption non valide. Veuillez réessayer.")

    def get_member(self, id):
        for member in self.members + self.librarians:
            if member.id == id:
                return member
        return None

    def get_book(self, isbn):
        for book in self.library.books:
            if book.isbn == isbn:
                return book
        return None

    def run(self):
        self.start()
        while True:
            self.menu()

    def quit(self):
        print("Merci d'avoir utilisé notre application. À bientôt !")
        exit()


if __name__ == "__main__":
    app = Application()
    app.run()

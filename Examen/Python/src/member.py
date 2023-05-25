class Member:
    def __init__(self, id, first_name, last_name, age):
        self.id = id
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.books_borrowed = []

    def borrow_book(self, book):
        self.books_borrowed.append(book)

    def return_book(self, book):
        self.books_borrowed.remove(book)

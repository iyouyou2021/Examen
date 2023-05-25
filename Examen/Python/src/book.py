class Book:
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn

    def __str__(self):
        return f"Titre: {self.title}, Auteur: {self.author}, ISBN: {self.isbn}"

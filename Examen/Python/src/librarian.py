from member import Member


class Librarian(Member):
    def __init__(self, id, first_name, last_name, age):
        super().__init__(id, first_name, last_name, age)


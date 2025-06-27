class Node:
    def __init__(self, data):  #self-->Refers to the current object being created.
        self.data = data
        self.next = None

class SLL:
    def __init__(self):
        self.First = None
        self.Last = None

    def display(self):
        temp = self.First
        if temp is None:
            print("List is empty.")
        else:
            while temp:
                print(f"{temp.data} ->", end="") # end=""--->it continues printing on the same line.
                temp = temp.next
            print("NULL")

    def insert_at_beginning(self, element):
        NewNode = Node(element)
        if self.First is None:
            self.First = self.Last = NewNode
        else:
            NewNode.next = self.First
            self.First = NewNode
        print(f"{self.First.data} was inserted at beginning.")

    def insert_at_end(self, element):
        NewNode = Node(element) #creates a new node object
        if self.First is None:
            self.First = self.Last = NewNode
        else:
            self.Last.next = NewNode
            self.Last = NewNode
        print(f"{self.Last.data} was inserted at end.")

    def insert_at_specificPosition(self, element, POS):
        if POS <= 0:
            print("Invalid Position.")
            return
        if POS == 1:
            self.insert_at_beginning(element)
            return
        temp = self.First
        i = 1
        while i < POS - 1 and temp is not None :
            temp = temp.next
            i += 1
        if temp is None:
            NewNode = Node(element)
            print(f"Data {NewNode.data} cannot insert , was out of bounds for position {POS}.")
            return
        if temp == self.Last:
            self.insert_at_end(element)
            return
        NewNode = Node(element)
        NewNode.next = temp.next
        temp.next = NewNode
        print(f"{NewNode.data} was inserted at position {POS}.")

    def delete_at_beginning(self):
        if self.First is None:
            print("List is empty.")
            return
        elif self.First.next is None:
            self.First = self.Last = None
        else:
            self.First = self.First.next
        print("Data was deleted from beginning.")

    def delete_at_end(self):
        if self.First is None:
            print("List is empty.")
        elif self.First.next is None:
            self.First = self.Last = None
        else:
            temp = self.First
            while temp.next != self.Last:
                temp = temp.next
            temp.next = None
            self.Last = temp
        print("Data was deleted from end.")

    def delete_at_specificPosition(self, POS):
        if POS <= 0:
            print("Invalid Deletion.")
            return
        if self.First is None:
            print("List is empty.")
            return
        if POS == 1:
            self.delete_at_beginning()
            return
        temp = self.First
        i = 1
        while i < POS - 1 and temp.next is not None :
            temp = temp.next
            i += 1
        if temp.next is None:
            print(f"Position out of bounds : Data cannot be deleted for position {POS}.")
            return
        if temp.next == self.Last:
            self.delete_at_end()
        else:
            tempp = temp.next
            temp.next = tempp.next
        print(f"Data was deleted from the {POS} position.")


sll = SLL() #Make a new empty singly linked list called sll / sll is an object of the SLL class
sll.insert_at_beginning(3)
sll.display()
sll.insert_at_end(5)
sll.display()
sll.insert_at_beginning(4)
sll.display()
sll.insert_at_specificPosition(1, 2)
sll.display()
sll.delete_at_beginning()
sll.display()
sll.insert_at_specificPosition(9, 3)
sll.display()
sll.delete_at_end()
sll.display()
sll.delete_at_specificPosition(2)
sll.display()
sll.insert_at_specificPosition(7, 8)
sll.display()
sll.delete_at_specificPosition(100)
sll.display()
sll.insert_at_specificPosition(8, 3)
sll.display()
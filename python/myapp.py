import sys

class MenuItem:
    def __init__(self, title, action):
        self.title = title
        self.action = action

    def __str__(self):
        return f"<MenuItem {self.title}>"

    def __repr__(self):
        return f"<MenuItem {self.title}>"

    def run(self):
        self.action()
        
class Menu:
    def __init__(self):
        self.menus= []

    def add_menu(self, menu_item):
        self.menus.append(menu_item)

    def print(self):
        print("[메뉴] ", end="")
        for i, menu in enumerate(self.menus):
            print(f"{i}:{menu.title}  ", end="")
        print()

    def run(self, select):
        if select >= len(self.menus):
            print("잘못된 메뉴 선택입니다.")
            return
        self.menus[select].run()        



class Application:
    def __init__(self):
        self.book = [1, 2, 3]
        self.menu = Menu()
        self.create_menu(self.menu)

    def create_menu(self, menu):	
        pass

    def exit(self):
        sys.exit(0)

    def run(self):
        while True:
            self.menu.print()
            sel = int(input("선택] "))
            self.menu.run(sel)
            print()        
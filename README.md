# Contens
- [Background⚙️](#background)
- [How to work🚀](#how-to-work)
- [Snapshots📷](#snapshots)
- [Issues to be fixed🛠️](#issues-to-be-fixed)
<br>



# Background
- Intened to make first simple program
- No Fancy UI, Just console base program.
- It looks good to me 😎
<br>

![home](img/home.gif)

# How to work
- Able to Manipulating the program by entering text information based on the guide shown in console window.
- It has functions that **Read/Write/Search/Delete** PhoneBook item. 
- No Database, but text file named *```phone-number.txt```* will be created when you add first item.


# Snapshots

* **Writing(Insert) new Item 📝**

![write](img/insert.gif)


* **Deleting existed Item 🗑️**

![Delete](img/delete.gif)


* **Searching existed Item 🔍**

![search](img/search.gif)


* **Reading and Printing All Item 🖨️**

![readAll](img/readAll.gif)


# Issues to be fixed
- [x] when there is no text file,
    - [x] search, it has to check whether the file is exist or not
    - [x] update, after checking the file, cursor is unable to move to next.
    - [x] delete, after checking the file, it should back to menu, however it asks which number of item would be deleted.
- [x] when deleting with written item in the file,
    - [x] after stopping and running the program again, when I delete specific item then some buffer text items are written in the file. but target of deleting has no problem. 
    - [x] sometimes all items are deleted when conducting delete menu.
- [x] Updating item,
    - [x] same behaviour with deleting process.... 
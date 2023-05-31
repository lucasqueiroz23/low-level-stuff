# simple code for creating a file. If the extension isn't given, 
# it'll add the ".txt" extension.

try:
    new_file_name = input("What's the name of your new file? ")

    # check if extension is given. 
    if not len(new_file_name.split(".", 1)) == 2:
        new_file_name += ".txt"
        
    new_file = open(new_file_name, "x")
    print(f'The file "{new_file_name}" was created!')

except Exception:
    print("This file already exists!")

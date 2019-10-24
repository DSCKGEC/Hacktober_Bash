import urllib.request


def read_text():
    #Open & read a file
    file = input("Copy paste the address of the file :: ")
    quotes = open(file)
    contents = quotes.read()
    quotes.close()
    check_for_profanity(contents)   

def check_for_profanity(text_for_check):
    word = text_for_check.split()
    words = '%20'.join(word)
    url = "http://www.wdylike.appspot.com/?q=" + words
    with urllib.request.urlopen(url) as response:
        profanity = response.read()
    if "true" in str(profanity):
        print("ALERT!!! Your text contains PROFANITY words.") 
    elif "false" in str(profanity):
        print("Your text is OK.")
    else:
        print("Unable to process. Please try again!")
read_text()      

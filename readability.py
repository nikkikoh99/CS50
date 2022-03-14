from cs50 import get_string


def calculate_readability():

    text = get_string("Paste text here: ")
    words = word_counter(text)
    L = letter_counter(text) / (words / 100)
    S = sentence_counter(text) / (words / 100)
    readability = (0.0588 * L) - (0.296 * S) - 15.8

    if readability < 1:
        print("Before Grade 1")

    # After Grade 16

    elif readability >= 16:
        print("Grade 16+")

    else:
        readability = round(readability)
        print("Grade " + str(readability))
        

def letter_counter(text):

    letter_count = 0

    for letter in text:
        if letter.isalpha() == True:
            letter_count += 1
    return letter_count


def word_counter(text):

    word_count = 1

    for letter in text:
        if letter == " ":
            word_count += 1
    return word_count
    

def sentence_counter(text):
    sentence_count = 0

    for index in range(len(text)):
        
        if text[index] == "!" or text[index] == "?":
            sentence_count += 1
            
        elif text[index] == ".":
            try:
                text[index + 1]
                if text[index + 1] == " ":
                    sentence_count += 1
                    continue
                
            except:
                sentence_count += 1
                return sentence_count
      
    return sentence_count


calculate_readability()

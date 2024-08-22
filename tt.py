import time

def calculate_typing_speed_and_accuracy(original_text, typed_text, start_time, end_time):
    # Calculate time taken in minutes
    time_taken = (end_time - start_time) / 60  # convert seconds to minutes
    
    # Calculate words per minute (WPM)
    word_count = len(typed_text.split())
    typing_speed_wpm = word_count / time_taken if time_taken > 0 else 0
    
    # Calculate accuracy
    original_words = original_text.split()
    typed_words = typed_text.split()
    
    correct_words = 0
    for original_word, typed_word in zip(original_words, typed_words):
        if original_word == typed_word:
            correct_words += 1
    
    accuracy = (correct_words / len(original_words)) * 100 if original_words else 0
    
    # Output result
    print(f"\nResults:\n"
          f"Typing Speed: {typing_speed_wpm:.2f} WPM\n"
          f"Accuracy: {accuracy:.2f}%\n"
          f"Correct Words: {correct_words}/{len(original_words)}\n")

def typing_tutor():
    # Prompt the user for text (paragraph input allowed)
    print("Enter the paragraph you want to use for the typing test (press Enter twice to finish):\n")
    
    original_text = []
    while True:
        line = input()
        if not line:  # Empty input means paragraph is finished
            break
        original_text.append(line)
    
    original_text = "\n".join(original_text)
    
    print("\nYour typing test begins now. Please retype the following paragraph:\n")
    print(original_text)
    
    # Start timer
    input("\nPress Enter to start typing...\n")
    start_time = time.time()
    
    # Get typed paragraph from user
    print("\nType the paragraph and press Enter twice when done:\n")
    
    typed_text = []
    while True:
        line = input()
        if not line:  # Empty input means typing is finished
            break
        typed_text.append(line)
    
    typed_text = "\n".join(typed_text)
    
    # End timer
    end_time = time.time()
    
    # Calculate and display results
    calculate_typing_speed_and_accuracy(original_text, typed_text, start_time, end_time)

if _name_ == "_main_":
    typing_tutor()

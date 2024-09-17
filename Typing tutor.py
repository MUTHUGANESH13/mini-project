import time

def calculate_typing_speed_and_accuracy(original_text, typed_text, start_time, end_time):

    # Calculate time taken in minutes
    time_taken_seconds = end_time - start_time
    time_taken_minutes = time_taken_seconds / 60  # Convert seconds to minutes
    
    # Print time taken
    print(f"Time taken: {time_taken_seconds:.2f} seconds")
    print(f"Time taken: {time_taken_minutes:.2f} minutes")
    
    # Calculate words per minute (WPM)
    typed_words = typed_text.split()
    word_count = len(typed_words)
    
    if time_taken_minutes > 0:
        typing_speed_wpm = word_count / time_taken_minutes
    else:
        typing_speed_wpm = 0

    # Print typing speed
    print(f"Total words typed: {word_count}")
    print(f"Typing Speed: {typing_speed_wpm:.2f} WPM")

    # Calculate accuracy
    original_words = original_text.split()
    
    # Counting correct words
    correct_words = sum(1 for o, t in zip(original_words, typed_words) if o == t)
    
    # Calculate accuracy percentage
    if original_words:
        accuracy = (correct_words / len(original_words)) * 100
    else:
        accuracy = 0

    # Print accuracy results
    print(f"Correct Words: {correct_words}/{len(original_words)}")
    print(f"Accuracy: {accuracy:.2f}%\n")

def get_paragraph(prompt):

    print(prompt)
    lines = []
    while True:
        line = input()
        if not line:  # Empty input ends the paragraph
            break
        lines.append(line)
    return "\n".join(lines)

def start_typing_test():

    # Prompt user to enter the original text
    original_text_prompt = "Enter the paragraph you want to use for the typing test (press Enter twice to finish):\n"
    original_text = get_paragraph(original_text_prompt)
    
    # Display the original text to the user for typing
    print("\nYour typing test begins now. Please retype the following paragraph:\n")
    print(original_text)
    
    # Wait for user to start typing
    input("\nPress Enter to start typing...\n")
    
    # Record the start time
    start_time = time.time()
    
    # Prompt user to type the paragraph
    typed_text_prompt = "Type the paragraph and press Enter twice when done:\n"
    typed_text = get_paragraph(typed_text_prompt)
    
    # Record the end time
    end_time = time.time()
    
    # Calculate and print results
    calculate_typing_speed_and_accuracy(original_text, typed_text, start_time, end_time)

def main():

    print("Welcome to the Typing Tutor Program!\n")
    start_typing_test()

if __name__ == "__main__":
    main()

#CHECK README
import tkinter as tk
from tkinter import scrolledtext


def penalty(a, b):
    if a == b:
        return 0
    vowels = "aeiou"
    a_is_vowel = a in vowels
    b_is_vowel = b in vowels
    if a_is_vowel == b_is_vowel:
        return 1
    return 3


def sequence_alignment(word1, word2):
    n = len(word1)
    m = len(word2)
    dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        dp[i][0] = dp[i - 1][0] + 2
    for j in range(1, m + 1):
        dp[0][j] = dp[0][j - 1] + 2

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            match = dp[i - 1][j - 1] + penalty(word1[i - 1], word2[j - 1])
            delete = dp[i - 1][j] + 2
            insert = dp[i][j - 1] + 2
            dp[i][j] = min(match, delete, insert)

    return dp[n][m]


def load_dictionary():
    dictionary_path = "C:/Users/StLec/OneDrive/Desktop/dictionary.txt"
    with open(dictionary_path, "r") as file:
        return [line.strip() for line in file]


def spell_check():
    input_word = entry.get()
    scores = {}

    for word in dictionary:
        score = sequence_alignment(input_word, word)
        if score in scores:
            scores[score].append(word)
        else:
            scores[score] = [word]

    suggestions_text.delete(1.0, tk.END)
    suggestion_count = 0
    for score, words in sorted(scores.items()):
        for word in words:
            suggestions_text.insert(tk.END, f"{word} (Score: {score})\n")
            suggestion_count += 1
            if suggestion_count >= 10:
                return


dictionary = load_dictionary()


root = tk.Tk()
root.title("Spell Checker")


entry = tk.Entry(root)
entry.pack()
check_button = tk.Button(root, text="Check", command=spell_check)
check_button.pack()
suggestions_text = scrolledtext.ScrolledText(root, wrap=tk.WORD)
suggestions_text.pack()


root.mainloop()

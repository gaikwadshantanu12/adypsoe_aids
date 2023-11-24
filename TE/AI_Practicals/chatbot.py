import nltk
from nltk.chat import Chat
reflection = {
    "I am":"you are",
    "I have":"you have",
    "I had":"you had"
}

pairs = [
    [r'I am(.*)',['Hello %1, how are you feeling today']],
    [r'feeling(.*)',['good to hear']],
    [r'I work(.*)',['Wow thats great']],
]

def chat():
    print("Hii there I am chatbot")
    chat = Chat(pairs,reflection)
    chat.converse()

chat()
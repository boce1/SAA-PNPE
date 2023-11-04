import re

sentence = "Act only according to that maxim whereby you can \
at the same time will that it should become a universal law."
em1 = "zarev.bojan2@gmail.com"
em2 = "zarev.bojan2@gmail."
em3 = "zarev.bojan2gmail.com"


patern = re.compile("^[A-Z][a-z]$")
patern2 = re.compile("Act\s[a-z]+")
patern_email = re.compile("^[A-Za-z0-9\.\_\-]+@{1}[A-Za-z]+\.{1}[a-z]+$")

#print(patern.search("Bojan"))
#print(patern.search("bOJAN"))
#print(patern.search("BDJFSF"))
#print(patern.search("Bojan is a great student"))

print(patern2.search(sentence))
print(patern_email.search(em1))
print(patern_email.search(em2))
print(patern_email.search(em3))

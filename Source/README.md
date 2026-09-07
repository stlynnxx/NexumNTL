# NexumNTL
Hello! This is the ReadMe for the Nexum
Neurotransmission Language, or NexumNTL.

NexumNTL is a compiled data transmission
and storage language for my project
EclecticAI (currently closed source).
EclecticAI is a cognitive substrate 
inspired by human psychology, physiology,
bayesian logic, and Neuromorpic principals.

NexumNTL sits as almost an analogue for an 
agnet's "Inner Thoughts", allowing for tokenization
for effiecent transmission and parsing of data.

It also plays a role in agentic memory, allowing
for rapid, tokenized importing and exporting of memories
via .nex files. 

# The basic schema

<i>MemoryKey : Association</i>

This is the crux of the language. Anything defined to the 
left of the colon is a Memory Key, and anything defined to
the right of the colon is an Assocation. Assocations hold details 
for a given Memory Key. A given Memory Key is capable of supporting multitudes
of Assocations, in a dictionary format.

Curly braces begin a new entry, and each entry should begin on it's own
line. 
{Memory Key : {Association}};

The opening braces define the entirety of the entry, with the semicolon acting
as a final delimiter for the line. 

Memory Keys can be used as Associations and "nest" any Associations they carry
within the Memory Key they are being referenced in. This is marked by placing
an Associator ("@") in front of the Memory Key being used as an Association.

{MemoryKeyOne: {"Association One"}};<br>
{MemoryKeyTwo: {"Associtaion One", @MemoryKeyOne}};

In the above example MemoryKeyOne and MemoryKeyTwo both have an Association One
that is exclusive to the respective Memory Key, however, since we nest the MemoryKeyOne
Memory Key using the Association, MemoryKeyTwo's Second Association would be the
entirety of MemoryKeyOne.

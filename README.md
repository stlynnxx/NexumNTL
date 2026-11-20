# NexumNTL

**An experimental memory-oriented language for human-inspired artificial intelligence.**

NexumNTL is an experimental programming language and compiler project being developed as part of the broader **Nexum Intelligentia** initiative. NexumNTL is designed to represent, organize, and communicate memories and their associations.

The project explores how structured memory representations can support cognitive architectures, knowledge transfer, associative reasoning, and communication between artificial cognitive units.

> **Project Status:** Early development. NexumNTL is experimental, and its syntax, internal structures, and implementation are subject to change.

## Project Vision

NexumNTL, at it's core, is designed around the associative nature of human memory and memory recall.
Traditional software systems often represent knowledge through databases, objects, graphs, or serialized documents. NexumNTL explores a different approach; memories and associations as first-class concepts.
The long-term goal is to provide a structured representation that artificial agents can use to:

- Store and retrieve associative memories.
- Represent relationships between concepts and experiences.
- Exchange information between cognitive components.
- Import and export structured knowledge.
- Support knowledge transfer between agents and across generations of agents.
- Build interconnected memory structures that can evolve over time.

NexumNTL is intended to support **human-inspired intelligence**, rather than reproduce human intelligence or claim human-equivalent cognition.

## Core Concepts

### Memory Keys

A memory key identifies a memory or concept within the language.
Memory keys serve as reference points for storing and retrieving associated information.

### Associations

Associations represent information connected to a memory key.
A memory may contain multiple associations, allowing concepts to be represented through their relationships rather than isolated values.

### Associators

Associators are intended to establish relationships between memory structures, allowing references to other memory keys.
They are functionally memory keys used as associations, which embed their own associations along with them.

The language's syntax uses the `@` prefix to identify references to memory keys.

### Engrams

Engrams are the internal structures being developed to represent memories and their relationships.

The current C implementation explores structures for:

- Memory keys
- Dynamic buffers
- Association banks
- Associators
- Engram storage and identification

The engram system is intended to provide a foundation for storing and managing structured associative information.

## Experimental Syntax

The core language concept follows a memory-key and association structure:

```text
{'memoryKey':{'association', @associator}}
```

A conceptual example:

```text
{apple : {fruit, red, edible, @food}}
```

In this example:

- `apple` is the memory key.
- `fruit`, `red`, and `edible` are associations.
- `@food` represents a reference to another memory key.

**Note:** This example illustrates the intended language model. It should not be treated as a guarantee that the current parser accepts this exact syntax. The grammar remains under development.

## Architecture

NexumNTL is being implemented in C.

### Source Processing

Reads NexumNTL source files and identifies language elements such as memory keys, associations, and references.

### Parsing

Interprets source structure and organizes recognized elements into internal representations.

### Engram Store

Manages memory structures, their identifiers, and associated data.

Current development includes dynamic memory buffers, allocation, association management, and storage structures.

### Association Management

Provides mechanisms for organizing relationships between memory keys and their associated information.

### Source Emission

Explores the generation and formatting of NexumNTL representations.
The architecture is evolving as the language implementation develops.

## Intended Applications

NexumNTL is being designed with several potential applications in mind.

**Artificial cognitive architectures**

Representing memory structures for artificial agents and cognitive units.

**Inter-component communication**

Providing structured representations for information exchanged between components of an artificial cognitive system.

**Knowledge transfer**

Allowing structured knowledge to be exported, imported, and potentially shared between artificial agents.

**Agent training**

Exploring whether structured memory files can provide agents with reusable knowledge.

**Associative memory research**

Investigating how interconnected memory representations might support retrieval, reasoning, and adaptive behavior.

These are research and development goals, not claims of currently demonstrated capabilities.

## Development Roadmap

The following areas represent the project's intended development direction.

### Language Foundation
- Formalize the NexumNTL grammar.
- Establish consistent syntax validation.
- Improve parsing and error reporting.
- Define memory-key and association semantics.

### Memory Infrastructure
- Continue developing the engram store.
- Improve dynamic memory management.
- Implement reliable association handling.
- Establish persistent memory identifiers.
- Develop memory lookup and retrieval mechanisms.

### Language Tooling
- Expand source parsing capabilities.
- Improve source emission and formatting.
- Develop testing and validation infrastructure.
- Document the language specification.

### Long-Term Research
- Explore communication between cognitive units.
- Investigate structured knowledge import and export.
- Explore integration with Nexum Intelligentia agents.
- Evaluate associative memory performance and scalability.

*This roadmap describes planned areas of work, not a fixed release schedule. Some foundational work is already in progress.*

## Contributing

Contributions have yet to truly open.

**AI Policy**: Please refrain from submitting 100% AI generated code.
I personally use AI in my daily workflow, in the form of seeking answers to syntax questions, looking over code, light debugging, and so forth,
but this project has 100% human designed and written from the start and will continue that tradition on.
There's no need to disclose AI use in your workflow if it's similar to what I've described above.
Whenever further documentation is needed I will accept looser AI standards around that, but I would like at a minimum for the contributor to take an outline and 
say it in their voice, or something along those lines, but the rule remains firm whenever it comes to code. 

## Project Philosophy

NexumNTL is part of a broader effort to investigate alternative approaches to artificial intelligence and computational cognition.
Its development is guided by curiosity, experimentation, and the belief that meaningful progress sometimes requires exploring architectures beyond established conventions.
The project does not assume that human-inspired computational structures will necessarily produce intelligence. Instead, it aims to provide tools and representations through which those ideas can be investigated.

## Relationship to Nexum Intelligentia

Nexum Intelligentia is a broader research initiative exploring human-inspired artificial intelligence, including cognitive units, memory, genetics-inspired representations, and agent interaction.
NexumNTL focuses specifically on the language and memory-representation aspects of that vision.
While the two projects are related, NexumNTL is being developed as a distinct technical component.

More to come on this!

---

**Nexum Intelligentia**

*Rewriting the current tech narrative through superior design and open-hearted machines.*

- Structural patterns design how objects are used for building larger structure.
- Behavioural patterns handle communication between objects, how they relate, interact and distribute responsibilities.


# Singleton example: when u have an app, and error happen. You would want a single instance of logger, handling logs everywhere.
- Other examples are database instances.
- problem: multi threading safe instances.
# Builder pattern: imagine having constructor with fifteen different optional parameters. For example complex api request, headers, body requests, retry logic.. Doing everything in a single constructor is heavy.
- Well, use a builder to build the request, and chain methods for building each part of the request.
- If u want to add a new field, u just create a new method.
- Used when u have more parameters than you the number of ur fingers.
# Factory pattern: instead of determining type of objects to create in the client, well create a factory class that takes of that. Removes all the messy logic from the main code.
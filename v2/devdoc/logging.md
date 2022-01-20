# `c-logging` requirements

## Basic functionality

`c-logging` shall expose APIs allowing the user to log events that can be used for observing the software activity, debugging, etc.

The exposeed API shall allow printf-like formatting.

## Log levels

The following log levels shall be exposed by the library:

- CRITICAL

- WARNING

- ERROR

- INFO

- VERBOSE

## Sinks

Multiple sinks shall be supported. Setting up which sinks to be used once shall be supported (so that they do not have to be specified every time a `c_logging_log` call is made).

### ETW sink

An `ETW` sink shall be supported so that events are emitted via TraceLogging.

For the `ETW` sink there should be a posibility of specifying the provider to use.

### console sink

A console sink shall be supported so that events are printed to the console using `printf`.

## API

```c
void c_logging_log(LOG_LEVEL log_level, const char* fmt, ...);
void c_logging_log_with_context(LOG_LEVEL log_level, LOG_CONTEXT_HANDLE log_context, const char* fmt, ...);
```

## Contextual logging

For each log line the library shall support specifying a context to be added to the log line.

The context shall allow defining pairs of properties that are added to the event when the event is emitted.

### Context creation from existing values

The library shall support creating a context without allocating any memory:

```c
#define LOG_CONTEXT_DEFINE(log_context, ...) \
```

where `...` is a list of pairs of the form (type, value).

Example:

```c
    LOG_CONTEXT_DEFINE(log_context,
        THANDLE(RC_STRING), block_id);
```

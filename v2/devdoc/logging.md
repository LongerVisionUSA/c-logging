# `c-logging` requirements

## Basic functionality

`c-logging` shall expose APIs allowing the user to log events that can be used for observing the software activity, debugging, etc.

The exposeed API shall allow printf-like formatting.

## Log levels

The following log levels shall be exposed by the library:

- `CRITICAL`

- `WARNING`

- `ERROR`

- `INFO`

- `VERBOSE`

## Sinks

Multiple sinks shall be supported. Setting up globally which sinks to be used shall be supported (so that they do not have to be specified every time a `c_logging_log` call is made).

### ETW sink

An `ETW` sink shall be supported so that events are emitted via TraceLogging.

For the `ETW` sink there should be a posibility of specifying the provider to use.

### console sink

A console sink shall be supported so that events are printed to the console using `printf`.

## API

```c
void logger_log(LOG_LEVEL log_level, LOG_CONTEXT_HANDLE log_context, const char* format, ...);
```

`log_context` may be `NULL`. If `log_context` is `NULL`, no context information shall be added to the log line.

`format` shall be a `printf`-like format string.

`...` shall be the variable number of arguments required by `format`.

## Contextual logging

For each log line the library shall support specifying a context to be added to the log line.

The context shall allow defining pairs of properties that are added to the event when the event is emitted.

### Local stack context creation

The library shall support defining a context using only stack memory, not requiring any memory allocation:

```c
#define LOCAL_LOG_CONTEXT_DEFINE(log_context, parent_context, ...) \
```

where `...` is a list of context fields defined using `LOG_CONTEXT_FIELD`.

Example:

```c
    LOCAL_LOG_CONTEXT_DEFINE(log_context, NULL, LOG_CONTEXT_FIELD("property_name", "%s", MU_P_OR_NULL(prop_value)));
```

### Dynamically allocated context creation

The library shall support creating a dynamically allocated context.

```c
#define LOG_CONTEXT_CREATE(log_context_handle, parent_context, ...) \

#define LOG_CONTEXT_CREATE(log_context_handle) \
```

where `...` is a list of context fields defined using `LOG_CONTEXT_FIELD`.

Example:

```c
    LOG_CONTEXT_CREATE(dynamically_allocated_log_context, NULL, LOG_CONTEXT_FIELD("property_name", "%s", MU_P_OR_NULL(prop_value)));
    LOG_CONTEXT_DESTROY(dynamically_allocated_log_context);
```

### Context chaining

It shall be supported to chain contexts (define a context or create a context dynamically while specifying a parent context to inherit the information from).

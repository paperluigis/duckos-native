# duckOS native JS API

### Types
- `BufferLike`
A string, Uint8Array or ArrayBuffer
- `fd`
A number that represents a file descriptor handle (this is gonna be used on return types)

### API Docs

- `api`
Main API object
- `api.fd.write(fd: number, data: BufferLike)`
Writes to the file descriptor `fd` with `data`
- `api.fd.read(fd: number): ArrayBuffer`
Reads from `fd` and returns an `ArrayBuffer`
- `api.fd.seek()`
TODO: document this
- `api.fd.dup(fd: number): fd`
Duplicate a file descriptor.
- `api.fd.close(fd: number)`
Closes `fd` file descriptor.
- `api.fd.ioctl()`
TODO: document this
- `api.fd.open.blackhole(): fd`
Opens a black hole (discard everything thrown at it) file descriptor
and returns the file descriptor.
- `api.fd.open.pipe(): number`
TODO: document this
- `api.fs.chwd(wd: string)`
Change working directory of the process to `wd`
- `api.fs.readdir(dir: string): string[]`
Read directory `dir` and return a list of files/folders in it.
- `api.fs.getwd(): string`
Get working directory.
- `api.fs.open(file: string, mode: string): fd`
Open a file and returns a file descriptor.
- `api.fs.stat(file: string): stat_t`
Return a file stat.
- `api.fs.mkdir(path: string)`
Makes a directory in `path`
- `api.fs.rmdir(path: string)`
Attempt to remove a directory
- `api.fs.unlink(path: string)`
Unlinks/deletes `path`.
- `api.fs.exists(path: string)`
Check if `path` exists
- `api.proc.getpid()`
Get process PID.
- `api.proc.exit(retc: number)`
Exit with `retc` return code.
- `api.proc.wait(pid: number)`
Waits for `pid` to end
- `api.proc.proc(): number`
Creates a process returning a PID.
TODO: finish documenting this
- `api.proc.kill(pid: number): boolean`
Kills process with pid `pid` and returns true on success.
- `api.environ.set(name: string, value: string)`
Sets a environment variable.
- `api.environ.get(name: string): string`
Returns the value of environment variable named `name`.
- `api.environ.list(): { [key: string]: string }`
Returns a list of all environment variables


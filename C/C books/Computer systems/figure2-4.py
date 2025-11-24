import struct

def show_bytes(bytez: bytes) -> None:
    """Print each byte in hex (like printf(\"%.2x\"))"""
    print(''.join(f'{byte:02x}' for byte in bytez))

def show_int(x: int) -> None:
    # '=i' = native endianness, 4-byte int, standard size
    packed = struct.pack('=i', x)
    show_bytes(packed)

def show_float(x: float) -> None:
    # '=f' = native endianness, 4-byte float
    packed = struct.pack('=f', x)
    show_bytes(packed)

def show_pointer(obj) -> None:
    """
    Rough analogue of show_pointer in C.
    Uses id(obj) as an address-like integer and packs it
    as a native pointer-sized value.
    Note: CPython-specific and not truly the same as C.
    """
    addr = id(obj)
    packed = struct.pack('P', addr)  # 'P' = void* size
    show_bytes(packed)

def show_string(s: str) -> None:
    """
    C's show_string prints the bytes of the char* including the
    terminating '\0', so we do the same.
    """
    b = s.encode('utf-8') 
    show_bytes(b)


# Example usage (similar to how you'd test it in C)
if __name__ == "__main__":
    show_int(12345)
    show_float(12345.0)
    show_string("12345")
    x = object()
    show_pointer(x)
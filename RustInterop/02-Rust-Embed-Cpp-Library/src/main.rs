use std::ffi::CString;
use std::os::raw::c_char;

// Link to the C/C++ shared library.
#[link(name = "library")]
extern "C" {
    // Declare the external C/C++ functions we want to use.
    fn Greet(name: *const c_char);
    fn AddNumbers(a: i32, b: i32) -> i32;
}

fn prompt(s: &str) -> String {
    use std::io::Write;
    print!("{}", s);
    std::io::stdout().flush().unwrap();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

// Safe wrapper around the unsafe C/C++ add_numbers function.
pub fn greet(name: CString) {
    unsafe {
        Greet(name.as_ptr())
    }
}

// Safe wrapper around the unsafe C/C++ add_numbers function.
pub fn add_numbers(a: i32, b: i32) -> i32 {
    unsafe {
        AddNumbers(a, b)
    }
}

fn main() {
    let name = prompt("[Rust]: What's your name? ");
    let c_name = CString::new(name).unwrap();
    greet(c_name);
    let result = add_numbers(10, 12);
    println!("[Rust]: addition result: {}", result);
}

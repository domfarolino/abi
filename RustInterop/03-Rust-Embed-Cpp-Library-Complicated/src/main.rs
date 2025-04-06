use std::ffi::CString;
use std::os::raw::c_char;

#[repr(C)]
pub struct LibraryAPI {
    size: usize,
    print_string_fn_ptr: Option<extern "C" fn(*const c_char)>,
    add_numbers_fn_ptr: Option<extern "C" fn(a: i32, b: i32) -> i32>,
}

#[link(name = "library")]
extern "C" {
    fn GetLibraryAPI(api: *mut LibraryAPI, requested_size: usize);
}

static mut API: Option<LibraryAPI> = None;

pub fn init() {
    println!("[Rust]: calling C's GetLibraryAPI to fill out function table");
    unsafe {
        let mut api = LibraryAPI {
            size: std::mem::size_of::<LibraryAPI>(),
            print_string_fn_ptr: None,
            add_numbers_fn_ptr: None,
        };
        GetLibraryAPI(&mut api, std::mem::size_of::<LibraryAPI>());
        API = Some(api);
    }
}

pub fn print_name(name: CString) {
    unsafe {
        if let Some(api) = &API {
            if let Some(print_string_extern) = api.print_string_fn_ptr {
                print_string_extern(name.as_ptr());
            }
        }
    }
}

pub fn add_numbers(a: i32, b: i32) {
    unsafe {
        if let Some(api) = &API {
            if let Some(add_numbers_extern) = api.add_numbers_fn_ptr {
                let addition_result: i32 = add_numbers_extern(a, b);
                println!("[Rust]: addition_result: {}", addition_result);
            }
        }
    }
}

fn main() {
    init();
    let name = String::from("Dominic Farolino");
    let c_name = CString::new(name).unwrap();
    print_name(c_name);
    add_numbers(2, 3);
}

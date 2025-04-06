#[no_mangle]
pub unsafe extern "C" fn library_print_message() {
    println!("This is a message straight from rust");
}

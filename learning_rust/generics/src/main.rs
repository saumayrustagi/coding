fn main() {
    println!("Hello, world!");
    let a = Option::Some(5).unwrap();
    println!("{}",a);
}
// enum Option<T> {
//     Some(T),
//     None,
// }
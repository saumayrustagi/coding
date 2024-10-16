fn main() {
    // let v: Vec<u8> = vec![1, 2, 3];
    let a = 6;
    let b = a;
    println!("{} {}", a, b);
    let a = String::from("hello");
    let b = &a[..];
    println!("{} {}",b,a);
    // use String;
    println!("{}",String::from("ok"));
}

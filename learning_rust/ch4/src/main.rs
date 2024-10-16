fn main() {
    // let mut s = String::from("hello");
    // s.push_str(", world");
    // println!("{}",s);

    // let s1 = String::from("ok!");
    // do_sm(&s1);
    // println!("{}", s1);
    // println!("{}", first_word(&s));
    // let s = String::from("hello world");
    // let a = &s[..];
    // println!("{}",a);

    let a = [1, 2, 3, 4, 5];
    let slice = &a[1..3];
    for elem in slice.iter() {
        print!("{} ", elem);
    }
    println!();
}

// fn do_sm(bs: &String) -> String {
//     println!("{}", bs);
//     bs.to_string()
// }

// fn first_word(s: &String) -> usize {
//     let bytes = s.as_bytes();
//     for (i, &item) in bytes.iter().enumerate() {
//         if item == b' ' {
//             return i;
//         }
//     }
//     s.len()
// }

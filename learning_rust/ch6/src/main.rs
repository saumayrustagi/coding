// fn main() {
//     let home: IpAddr = IpAddr {
//         kind: IpAddrKind::V4,
//         address: String::from("127.0.0.1"),
//     };

//     let loopback: IpAddr = IpAddr {
//         kind: IpAddrKind::V6,
//         address: String::from("::1"),
//     };
//     println!("{}", loopback.address);
// }

// enum IpAddrKind {
//     V4,
//     V6,
// }

// struct IpAddr {
//     kind: IpAddrKind,
//     address: String,
// }

fn main() {
    let some_u8_value: Option<u8> = Some(0);
    match some_u8_value {
        Some(3) => println!("three"),
        _ => (),
    }
}

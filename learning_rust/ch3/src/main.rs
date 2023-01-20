fn main() {
    let a = 1;
    let _b = testing(a);
    println!("{a}");
}

fn testing(a: u32) -> u32 {
    a + 1
}

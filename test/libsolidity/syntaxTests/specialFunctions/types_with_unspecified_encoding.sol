contract C {
    struct S { uint x; }
    S s;
    struct T { }
    T t;
    enum A { X, Y }
    function f() public pure {
        bytes32 h = keccak256(keccak256, f, this.f.gas, block.blockhash);
        bool a = address(this).call(address(this).delegatecall, super);
        bool b = address(this).delegatecall(log0, tx, mulmod, S, A, T, uint, uint[]);
        bytes32 c = sha256(s, t);
        h; a; b; c;
    }
}
// ----
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.
// TypeError: This type cannot be encoded.

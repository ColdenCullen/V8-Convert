/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */
#if !defined(DOXYGEN)
/** Specialization for 1 arguments. */
template <typename T>
struct CtorForwarder<T,1>
{
    enum { Arity = 1 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0;  AC0 ac0;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,1>::Ctor() expects at least 1 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]) );
        }
    }

};
/** Specialization for 2 arguments. */
template <typename T>
struct CtorForwarder<T,2>
{
    enum { Arity = 2 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1;  AC0 ac0; AC1 ac1;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,2>::Ctor() expects at least 2 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]) );
        }
    }

};
/** Specialization for 3 arguments. */
template <typename T>
struct CtorForwarder<T,3>
{
    enum { Arity = 3 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1,  typename A2 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2;  AC0 ac0; AC1 ac1; AC2 ac2;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,3>::Ctor() expects at least 3 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]) );
        }
    }

};
/** Specialization for 4 arguments. */
template <typename T>
struct CtorForwarder<T,4>
{
    enum { Arity = 4 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1,  typename A2,  typename A3 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3;  AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,4>::Ctor() expects at least 4 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]) );
        }
    }

};
/** Specialization for 5 arguments. */
template <typename T>
struct CtorForwarder<T,5>
{
    enum { Arity = 5 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1,  typename A2,  typename A3,  typename A4 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4;  AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,5>::Ctor() expects at least 5 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]) );
        }
    }

};
/** Specialization for 6 arguments. */
template <typename T>
struct CtorForwarder<T,6>
{
    enum { Arity = 6 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5;  AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,6>::Ctor() expects at least 6 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]) );
        }
    }

};
/** Specialization for 7 arguments. */
template <typename T>
struct CtorForwarder<T,7>
{
    enum { Arity = 7 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6;  AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,7>::Ctor() expects at least 7 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]) );
        }
    }

};
/** Specialization for 8 arguments. */
template <typename T>
struct CtorForwarder<T,8>
{
    enum { Arity = 8 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7;  AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,8>::Ctor() expects at least 8 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]) );
        }
    }

};
/** Specialization for 9 arguments. */
template <typename T>
struct CtorForwarder<T,9>
{
    enum { Arity = 9 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8;  AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,9>::Ctor() expects at least 9 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]) );
        }
    }

};
/** Specialization for 10 arguments. */
template <typename T>
struct CtorForwarder<T,10>
{
    enum { Arity = 10 };
    typedef typename TypeInfo<T>::Type Type;
    typedef typename TypeInfo<T>::NativeHandle NativeHandle;
    template <  typename A0,  typename A1,  typename A2,  typename A3,  typename A4,  typename A5,  typename A6,  typename A7,  typename A8,  typename A9 >
    static NativeHandle Ctor( ::v8::Arguments const & argv )
    {
         typedef ArgCaster<A0> AC0; typedef ArgCaster<A1> AC1; typedef ArgCaster<A2> AC2; typedef ArgCaster<A3> AC3; typedef ArgCaster<A4> AC4; typedef ArgCaster<A5> AC5; typedef ArgCaster<A6> AC6; typedef ArgCaster<A7> AC7; typedef ArgCaster<A8> AC8; typedef ArgCaster<A9> AC9;  AC0 ac0; AC1 ac1; AC2 ac2; AC3 ac3; AC4 ac4; AC5 ac5; AC6 ac6; AC7 ac7; AC8 ac8; AC9 ac9;
	if( argv.Length() < Arity )
        {
            throw std::range_error("CtorForwarder<T,10>::Ctor() expects at least 10 JS arguments!");
        }
        else
        {
            return new Type(  ac0.ToNative(argv[0]),  ac1.ToNative(argv[1]),  ac2.ToNative(argv[2]),  ac3.ToNative(argv[3]),  ac4.ToNative(argv[4]),  ac5.ToNative(argv[5]),  ac6.ToNative(argv[6]),  ac7.ToNative(argv[7]),  ac8.ToNative(argv[8]),  ac9.ToNative(argv[9]) );
        }
    }

};
#endif // if !defined(DOXYGEN)



/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Tue Aug 29 14:19:05 2017
 */
/* Compiler settings for IUnknown_.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IUnknown__h__
#define __IUnknown__h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUnknown__FWD_DEFINED__
#define __IUnknown__FWD_DEFINED__
typedef interface IUnknown_ IUnknown_;
#endif 	/* __IUnknown__FWD_DEFINED__ */


#ifndef __CUnknown_FWD_DEFINED__
#define __CUnknown_FWD_DEFINED__

#ifdef __cplusplus
typedef class CUnknown CUnknown;
#else
typedef struct CUnknown CUnknown;
#endif /* __cplusplus */

#endif 	/* __CUnknown_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IUnknown__INTERFACE_DEFINED__
#define __IUnknown__INTERFACE_DEFINED__

/* interface IUnknown_ */
/* [uuid][object] */ 


EXTERN_C const IID IID_IUnknown_;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1372AE9E-5193-44f8-8111-2331E593BEF4")
    IUnknown_ : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Method( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnknown_Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnknown_ * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnknown_ * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnknown_ * This);
        
        HRESULT ( STDMETHODCALLTYPE *Method )( 
            IUnknown_ * This);
        
        END_INTERFACE
    } IUnknown_Vtbl;

    interface IUnknown_
    {
        CONST_VTBL struct IUnknown_Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnknown__QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnknown__AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnknown__Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnknown__Method(This)	\
    (This)->lpVtbl -> Method(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IUnknown__Method_Proxy( 
    IUnknown_ * This);


void __RPC_STUB IUnknown__Method_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnknown__INTERFACE_DEFINED__ */



#ifndef __UnknownLib_LIBRARY_DEFINED__
#define __UnknownLib_LIBRARY_DEFINED__

/* library UnknownLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_UnknownLib;

EXTERN_C const CLSID CLSID_CUnknown;

#ifdef __cplusplus

class DECLSPEC_UUID("94C0873F-A3E3-4d48-AECB-5B58DBED45FF")
CUnknown;
#endif
#endif /* __UnknownLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



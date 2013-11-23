#include"boda_tu_base.H"
#include"has_main.H"
#include"lexp.H"
#include"nesi.H"
#include"pyif.H"
namespace boda
{
  extern tinfo_t tinfo_p_has_main_t;

  void create_and_run_has_main_t( p_lexp_t lexp ) {
    // add top-level extra fields
    p_lexp_t boda_cfg = parse_lexp_xml_file( py_boda_dir() + "/lib/boda_cfg.xml" );
    //boda_cfg->deep_inc_use_cnt(); // it's okay not to use some/all of the config data, so mark it used
    lexp_name_val_map_t nvm;
    nvm.populate_from_lexp( boda_cfg.get() );
    // these won't insert if the field exists
    nvm.insert_leaf( "boda_dir", py_boda_dir().c_str() ); 
    nvm.insert_leaf( "boda_test_dir", py_boda_test_dir().c_str() );
    nvm.insert_leaf( "boda_output_dir", "." );
    // create and run mode
    p_has_main_t has_main;
    nesi_init_and_check_unused_from_lexp( &nvm, &tinfo_p_has_main_t, &has_main, lexp );
    has_main->main( &nvm );
  }
#include"gen/has_main.H.nesi_gen.cc"
}

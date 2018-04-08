

#include "headers/intro_master.h"

extern void exit_intro(void);
bool intro_main();


void init_intro_master(struct IntroSt ** pointer)
{
    *pointer = (struct IntroSt *) malloc_and_clear(sizeof(struct IntroSt));
    (*pointer)->bg_hv_mirror = (struct bg_hv_ofs (*)[4]) malloc_and_clear(sizeof(struct bg_hv_ofs[4]));
    
}

void free_intro_master(struct IntroSt ** pointer)
{
    free((*pointer)->bg_hv_mirror);
    free(*pointer);
}

void write_bg_positions(struct IntroSt *self)
{
    u8 i;
    for (i = 0; i < 4; i++)
    {
        BG_HV_OFS[i] = (*self->bg_hv_mirror)[i];
    }
}


void not_main()
{
    if (!(super.vblank_handler == vblank_function))
    {   
        vblank_handler_set(vblank_function);
        init_intro_master(&intro_master); 
        set_bg_config();
        
    } 
   
    if (intro_main())
    {
        free_intro_master(&intro_master);
		set_callback2(exit_intro);
        
    }
    update_everything();
    
}


void update_everything()
{
    task_exec();
    obj_sync_superstate();
    objc_exec();
    process_palfade();
}
 
void vblank_function()
{ 
    gpu_sprites_upload();
    copy_queue_process();
    gpu_pal_upload();
}

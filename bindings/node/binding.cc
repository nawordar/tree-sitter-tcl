#include "tree_sitter/parser.h"
#include <node.h>
#include "nan.h"

using namespace v8;

extern "C" TSLanguage * tree_sitter_tcl();
extern "C" TSLanguage * tree_sitter_tclsh();

namespace {

NAN_METHOD(New) {}

void Init(Local<Object> exports, Local<Object> module) {
  Local<FunctionTemplate> tcl_template = Nan::New<FunctionTemplate>(New);
  tcl_template->SetClassName(Nan::New("Language").ToLocalChecked());
  tcl_template->InstanceTemplate()->SetInternalFieldCount(1);
  Local<Function> tcl_constructor = Nan::GetFunction(tcl_template).ToLocalChecked();
  Local<Object> tcl_instance = tcl_constructor->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
  Nan::SetInternalFieldPointer(tcl_instance, 0, tree_sitter_tcl());
  Nan::Set(tcl_instance, Nan::New("name").ToLocalChecked(), Nan::New("tcl").ToLocalChecked());

  Local<FunctionTemplate> tclsh_template = Nan::New<FunctionTemplate>(New);
  tclsh_template->SetClassName(Nan::New("Language").ToLocalChecked());
  tclsh_template->InstanceTemplate()->SetInternalFieldCount(1);
  Local<Function> tclsh_constructor = Nan::GetFunction(tclsh_template).ToLocalChecked();
  Local<Object> tclsh_instance = tclsh_constructor->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
  Nan::SetInternalFieldPointer(tclsh_instance, 0, tree_sitter_tclsh());
  Nan::Set(tclsh_instance, Nan::New("name").ToLocalChecked(), Nan::New("tclsh").ToLocalChecked());

  Nan::Set(exports, Nan::New("tcl").ToLocalChecked(), tcl_instance);
  Nan::Set(exports, Nan::New("tclsh").ToLocalChecked(), tclsh_instance);
}

NODE_MODULE(tree_sitter_tcl_binding, Init)

}  // namespace

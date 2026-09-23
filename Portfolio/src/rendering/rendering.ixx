export module rendering;

import resources.signal;

export namespace rendering {

Signal<const double> onRender;

void initialize();

}
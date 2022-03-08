/*
 * This code describes the frontend of our application.
 * Ideally, the frontend would be instantiated such that it is a singleton;
 * however this instantiation is optional.
 * 
 * @author Robert F Cooper <robert.cooper@marquette.edu>
 * @version 1.2
 */
#include <future>
 
namespace Batch{
    namespace FrontEnd{
		/*
		* MainPane-
		* This class is designed to be instantiated as a singleton.
		* If not, it can be embedded as a panel in other instance.
		* This panel is responsible for encapsulating a variety of things,
		* and thus must be responsible with its layout.
		*/
        class MainPane : public BasePane{
            private:
				// @var ScalePane - This panel will be place on the left side,
				// and will be responsible for displaying all scale information
				// and allowing for its update.
                ScalePane scalePane;
				// @var SelectionPane - This panel will allow the user to select
				// and update items in the other panels.
                SelectionPane selectPane;
				// @var ResultPane - this panel will display all results from the
				// backend.
                ResultPane resPane;
            protected:
				// @var OperationsPane - this panel will allow users to adjust
				// aspects of the backend runtime.
                OperationsPane opPane;
			public:					
				/* startBatch:
				// This will start the batch process, using the supplied thread pool.
				// @param batchPool - the pool of threads we'll use for the analysis.
				// @result - the future corresponding to the thread we supplied to
				*/ the thread pool.
				std::future<BatchResult> startBatch(BackEnd::ThreadPool batchPool);
				// stopBatch:
				// Signals the batch pool to stop, interrupting all executing work.
				void stopBatch();
				// repaint:
				// Takes all items and runs them through a validation and refresh
				// to update their appearances on the screen.
				void repaint();
				
        };
    }
}
/**
 *
 * This plugin determines the spacings of the currently displayed set of coordinates.
 * This version calculates the:
 * - Mean Nearest Neighbor
 * - Mean Inter-cell
 * - Mean Furthest Neighbor
 * spacings. These can be calculated across all coordinates, or only coordinates
 * which have bound Voronoi regions. A Voronoi cell is considered bound if:
 * 
 * +None of its vertices fall outside the canvas area.
 * +The cell is a closed polygon.
 * 
 * It does this using the Mosaic Voronoi implementation.
 * It converts the Voronoi diagram to a Delaunay diagram, @see DelaunayDiagram
 * and calculates the spacings of each cell.
 * Note: If there are multiple coordinate sets in the current canvas, then 
 * it calculates the spacing of each set separately and returns the results.
 * 
 * @author Robert F Cooper <robert.cooper@marquette.edu>
 * @version 1.1
 */
 #include <boost/geometry/geometries/point_xy.hpp>
 #include "TII.hpp"
 
 
 namespace Spacings{
	 
	 // -- SpacingAnalyzer --
	 // This class encapsulates multiple ways to calculate spacing from a given scale, coordinate list, and image.
	 // As a general rule, it will only return spacing values that are from the entire ROI.
	 class SpacingAnalyzer : public TII::plugins {
		public:
			// SpacingAnalyzer:
			// @param scale: The x/y scale of the coordinates and image that follows.
			// @param coordList: The list of coordinates that we will be assessing.
			// @param img: The image that the coordinates are based on. 
			// 				This will be used as the bounding 
			SpacingAnalyzer(TII::Scale scale, TII::CoordinateList coordList, TII::Image img);
			// startAnalysis:
			// Starts the analysis process.
			MASResult startAnalysis();
			// getName:
			// Gets the name of the plugin.
			// @return: The name of the plugin as a std::string
			std::string getName();
			// isBatchable:
			// Returns whether or not the plugin is able to run in batch mode.
			bool isBatchable();
		protected:
		private:
			const std::string pluginName; // The plugin name.
			TII::Scale scale;
			TII::CoordinateList list;
			TII::Image img;
			// initalizeParams:
			// Initializes the parameters by itself, or asks the user for input.
			void initalizeParams();
			/* getDistances:
			* A function designed to calculate the distance from a single point to all other points
			* @param thisPoint: The test point.
			* @param thosePoints: A list of reference points that we'll be calculating the distances to.
			* @return: A std::vector of distances corresponding on the distance between thisPoint and thosePoints
			*/
			std::vector<double> getDistances(bg::model::d2::point_xy<double> thisPoint, std::vector<bg::model::d2::point_xy<double>> thosePoints);
			
			Spacings::CoordinateSpacings generateSpacing(TII::DelaunayDiagram diagram);
	 }
 }